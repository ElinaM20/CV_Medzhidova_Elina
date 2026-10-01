// ==================== Hostel.h ====================
#ifndef HOSTEL_H
#define HOSTEL_H

#include "Room.h"
#include <vector>
#include <memory>

class Hostel {
    std::vector<Room*> rooms;          // владеет объектами через указатели

public:
    ~Hostel();

    // --- Пункты меню ---
    void addRoom();                    // добавить комнату (общая/отдельная)
    void showAllRooms() const;         // краткий список
    void showDetailedDescriptions() const;  // полиморфный вызов getRoomDescription()
    void calculateStayCost() const;    // calcNightCost с вводом номера и числа гостей
    void checkInGuest();               // заселить гостя
    void checkOutGuest();              // выселить гостя
    void findRoomByNumber() const;     // найти по номеру
    void showStatistics() const;       // статистика (всего комнат, занято/свободно, средняя цена)
    void deleteRoom();                 // удалить комнату

    // --- Вспомогательные функции ---
    Room* findRoom(int number) const;  // возвращает указатель или nullptr
    bool isRoomNumberUnique(int number) const;

    // --- Утилиты ввода ---
    static int readInt(const std::string& prompt, int min = 1, int max = INT_MAX);
    static double readDouble(const std::string& prompt, double min = 0.0);
};

#endif