// ==================== Room.h ====================
#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
protected:
    int roomNumber;
    int capacity;         // максимальное число гостей
    int currentGuests;    // сколько гостей сейчас проживает
    std::string roomType; // "Shared" или "Private"

public:
    Room(int number = 0, int cap = 1, const std::string& type = "");
    virtual ~Room() = default;

    // --- Чисто виртуальные функции ---
    virtual double calcNightCost(int guests) const = 0;   // расчёт стоимости для гостей
    virtual std::string getRoomDescription() const = 0;   // полное описание

    // --- Геттеры и сеттеры с валидацией ---
    int getNumber() const;
    void setNumber(int number);               // > 0

    int getCapacity() const;
    void setCapacity(int capacity);           // > 0

    int getCurrentGuests() const;
    // прямого сеттера на currentGuests нет – используем checkIn/checkOut

    std::string getType() const;

    // --- Операции заселения / выселения ---
    bool checkIn(int guests);                 // заселить, если хватает мест
    bool checkOut(int guests);                // выселить, если не больше, чем проживает
};

#endif