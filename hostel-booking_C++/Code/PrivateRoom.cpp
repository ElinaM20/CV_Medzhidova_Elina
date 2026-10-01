// ==================== PrivateRoom.cpp ====================
#include "PrivateRoom.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>

PrivateRoom::PrivateRoom(int number, int capacity, double pricePerNight)
    : Room(number, capacity, "Private"), pricePerNight(pricePerNight)
{
    setPricePerNight(pricePerNight);
}

double PrivateRoom::getPricePerNight() const { return pricePerNight; }

void PrivateRoom::setPricePerNight(double price) {
    if (price <= 0)
        throw std::invalid_argument("Price per night must be positive.");
    pricePerNight = price;
}

double PrivateRoom::calcNightCost(int guests) const {
    if (guests <= 0 || guests > capacity)
        return -1.0;               // сигнал ошибки
    return pricePerNight;          // фиксированная цена за комнату
}

std::string PrivateRoom::getRoomDescription() const {
    std::ostringstream oss;
    oss << "Room #" << roomNumber << " (Private)\n"
        << "  Max guests: " << capacity << "\n"
        << "  Currently occupied: " << currentGuests << " guest(s)\n"
        << "  Price per night: " << std::fixed << std::setprecision(2) << pricePerNight << " rub\n";
    return oss.str();
}