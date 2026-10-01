// ==================== SharedRoom.cpp ====================
#include "SharedRoom.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

SharedRoom::SharedRoom(int number, int capacity, double pricePerBed)
    : Room(number, capacity, "Shared"), pricePerBed(pricePerBed)
{
    setPricePerBed(pricePerBed);
}

double SharedRoom::getPricePerBed() const { return pricePerBed; }

void SharedRoom::setPricePerBed(double price) {
    if (price <= 0)
        throw std::invalid_argument("Price per bed must be positive.");
    pricePerBed = price;
}

double SharedRoom::calcNightCost(int guests) const {
    if (guests <= 0 || guests > capacity)
        return -1.0;               // сигнал ошибки
    return guests * pricePerBed;
}

std::string SharedRoom::getRoomDescription() const {
    std::ostringstream oss;
    oss << "Room #" << roomNumber << " (Shared dormitory)\n"
        << "  Beds: " << capacity << "\n"
        << "  Occupied: " << currentGuests << " beds\n"
        << "  Price per bed: " << std::fixed << std::setprecision(2) << pricePerBed << " rub\n";
    return oss.str();
}