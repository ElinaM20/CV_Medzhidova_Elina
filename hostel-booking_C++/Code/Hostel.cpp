// ==================== Hostel.cpp ====================
#include "Hostel.h"
#include "SharedRoom.h"
#include "PrivateRoom.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <iomanip>

Hostel::~Hostel() {
    for (Room* r : rooms)
        delete r;
}

// ---------- Чтение с валидацией ----------
int Hostel::readInt(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max)
            return value;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again.\n";
    }
}

double Hostel::readDouble(const std::string& prompt, double min) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min)
            return value;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try again.\n";
    }
}

// ---------- Поиск комнаты ----------
Room* Hostel::findRoom(int number) const {
    auto it = std::find_if(rooms.begin(), rooms.end(),
        [number](const Room* r) { return r->getNumber() == number; });
    return (it != rooms.end()) ? *it : nullptr;
}

bool Hostel::isRoomNumberUnique(int number) const {
    return findRoom(number) == nullptr;
}

// ---------- Добавление комнаты ----------
void Hostel::addRoom() {
    std::cout << "\n--- Add room ---\n";
    int type = readInt("Type (1 - Shared, 2 - Private): ", 1, 2);
    int number = readInt("Room number: ", 1);
    if (!isRoomNumberUnique(number)) {
        std::cout << "Room with this number already exists!\n";
        return;
    }
    int capacity = readInt("Capacity (max guests): ", 1);

    if (type == 1) {
        double price = readDouble("Price per bed: ", 0.01);
        rooms.push_back(new SharedRoom(number, capacity, price));
    } else {
        double price = readDouble("Price per night (whole room): ", 0.01);
        rooms.push_back(new PrivateRoom(number, capacity, price));
    }
    std::cout << "Room added.\n";
}

// ---------- Краткий список всех комнат ----------
void Hostel::showAllRooms() const {
    if (rooms.empty()) {
        std::cout << "No rooms.\n";
        return;
    }
    std::cout << "\n--- All rooms (short) ---\n";
    for (const Room* r : rooms) {
        std::cout << "Room #" << r->getNumber() << " (" << r->getType() << ") - "
                  << r->getCurrentGuests() << "/" << r->getCapacity() << "\n";
    }
}

// ---------- Подробное описание (полиморфный вызов) ----------
void Hostel::showDetailedDescriptions() const {
    if (rooms.empty()) {
        std::cout << "No rooms.\n";
        return;
    }
    std::cout << "\n--- Detailed descriptions ---\n";
    for (const Room* r : rooms) {
        std::cout << r->getRoomDescription() << "\n";
    }
}

// ---------- Расчёт стоимости проживания ----------
void Hostel::calculateStayCost() const {
    int number = readInt("Enter room number: ", 1);
    Room* room = findRoom(number);
    if (!room) {
        std::cout << "Room not found.\n";
        return;
    }
    int guests = readInt("Number of guests: ", 1);
    double cost = room->calcNightCost(guests);
    if (cost < 0) {
        std::cout << "Cannot accommodate " << guests << " guests (max " << room->getCapacity() << ").\n";
    } else {
        std::cout << "Cost for " << guests << " guest(s) per night: "
                  << std::fixed << std::setprecision(2) << cost << " rub\n";
    }
}

// ---------- Заселение ----------
void Hostel::checkInGuest() {
    int number = readInt("Enter room number: ", 1);
    Room* room = findRoom(number);
    if (!room) {
        std::cout << "Room not found.\n";
        return;
    }
    int guests = readInt("How many guests to check in? ", 1);
    if (room->checkIn(guests))
        std::cout << "Successfully checked in " << guests << " guest(s).\n";
    else
        std::cout << "Not enough free beds (free: " << room->getCapacity() - room->getCurrentGuests() << ").\n";
}

// ---------- Выселение ----------
void Hostel::checkOutGuest() {
    int number = readInt("Enter room number: ", 1);
    Room* room = findRoom(number);
    if (!room) {
        std::cout << "Room not found.\n";
        return;
    }
    int guests = readInt("How many guests to check out? ", 1);
    if (room->checkOut(guests))
        std::cout << "Successfully checked out " << guests << " guest(s).\n";
    else
        std::cout << "There are only " << room->getCurrentGuests() << " guest(s) in the room.\n";
}

// ---------- Поиск по номеру ----------
void Hostel::findRoomByNumber() const {
    int number = readInt("Enter room number: ", 1);
    Room* room = findRoom(number);
    if (!room) {
        std::cout << "Room not found.\n";
    } else {
        std::cout << room->getRoomDescription();
    }
}

// ---------- Статистика ----------
void Hostel::showStatistics() const {
    if (rooms.empty()) {
        std::cout << "No rooms.\n";
        return;
    }
    int totalRooms = static_cast<int>(rooms.size());
    int occupiedPlaces = 0;
    int totalPlaces = 0;      // сумма capacity
    double totalCostOneGuest = 0.0;

    for (const Room* r : rooms) {
        occupiedPlaces += r->getCurrentGuests();
        totalPlaces   += r->getCapacity();
        double cost = r->calcNightCost(1);   // стоимость для 1 гостя (всегда корректна, т.к. capacity >= 1)
        if (cost > 0)
            totalCostOneGuest += cost;
    }
    int freePlaces = totalPlaces - occupiedPlaces;
    double avgPrice = totalCostOneGuest / totalRooms;

    std::cout << "\n--- Hostel statistics ---\n";
    std::cout << "Total rooms: " << totalRooms << "\n";
    std::cout << "Occupied places: " << occupiedPlaces << "\n";
    std::cout << "Free places: " << freePlaces << "\n";
    std::cout << "Average price per night (for 1 guest): "
              << std::fixed << std::setprecision(2) << avgPrice << " rub\n";
}

// ---------- Удаление комнаты ----------
void Hostel::deleteRoom() {
    int number = readInt("Enter room number to delete: ", 1);
    auto it = std::find_if(rooms.begin(), rooms.end(),
        [number](const Room* r) { return r->getNumber() == number; });
    if (it == rooms.end()) {
        std::cout << "Room not found.\n";
        return;
    }
    delete *it;
    rooms.erase(it);
    std::cout << "Room deleted.\n";
}