// ==================== Room.cpp ====================
#include "Room.h"
#include <stdexcept>

Room::Room(int number, int cap, const std::string& type)
    : roomNumber(number), capacity(cap), currentGuests(0), roomType(type)
{
    setNumber(number);
    setCapacity(cap);
}

int Room::getNumber() const { return roomNumber; }

void Room::setNumber(int number) {
    if (number <= 0)
        throw std::invalid_argument("Room number must be positive.");
    roomNumber = number;
}

int Room::getCapacity() const { return capacity; }

void Room::setCapacity(int capacity) {
    if (capacity <= 0)
        throw std::invalid_argument("Capacity must be positive.");
    this->capacity = capacity;
}

int Room::getCurrentGuests() const { return currentGuests; }

std::string Room::getType() const { return roomType; }

bool Room::checkIn(int guests) {
    if (guests <= 0) return false;
    if (currentGuests + guests <= capacity) {
        currentGuests += guests;
        return true;
    }
    return false;
}

bool Room::checkOut(int guests) {
    if (guests <= 0) return false;
    if (guests <= currentGuests) {
        currentGuests -= guests;
        return true;
    }
    return false;
}