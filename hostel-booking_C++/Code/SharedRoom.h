// ==================== SharedRoom.h ====================
#ifndef SHAREDROOM_H
#define SHAREDROOM_H

#include "Room.h"

class SharedRoom : public Room {
    double pricePerBed;   // цена за одно место

public:
    SharedRoom(int number, int capacity, double pricePerBed);

    double getPricePerBed() const;
    void setPricePerBed(double price);          // > 0

    double calcNightCost(int guests) const override;
    std::string getRoomDescription() const override;
};

#endif