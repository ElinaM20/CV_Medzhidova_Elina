// ==================== PrivateRoom.h ====================
#ifndef PRIVATEROOM_H
#define PRIVATEROOM_H

#include "Room.h"

class PrivateRoom : public Room {
    double pricePerNight;   // цена за всю комнату за ночь

public:
    PrivateRoom(int number, int capacity, double pricePerNight);

    double getPricePerNight() const;
    void setPricePerNight(double price);       // > 0

    double calcNightCost(int guests) const override;
    std::string getRoomDescription() const override;
};

#endif