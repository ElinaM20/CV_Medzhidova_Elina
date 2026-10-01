// ==================== main.cpp ====================
#include "Hostel.h"
#include <iostream>
#include <limits>

void showMenu() {
    std::cout << "\n========== HOSTEL MANAGEMENT ==========\n"
              << "1. Add room (shared/private)\n"
              << "2. Show all rooms (short)\n"
              << "3. Calculate stay cost (polymorphic calcNightCost)\n"
              << "4. Show detailed descriptions (polymorphic getRoomDescription)\n"
              << "5. Check-in guest\n"
              << "6. Check-out guest\n"
              << "7. Find room by number\n"
              << "8. Show statistics\n"
              << "9. Delete room\n"
              << "0. Exit\n"
              << "Your choice: ";
}

int main() {
    Hostel hostel;
    int choice;
    while (true) {
        showMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера

        switch (choice) {
        case 1: hostel.addRoom(); break;
        case 2: hostel.showAllRooms(); break;
        case 3: hostel.calculateStayCost(); break;
        case 4: hostel.showDetailedDescriptions(); break;
        case 5: hostel.checkInGuest(); break;
        case 6: hostel.checkOutGuest(); break;
        case 7: hostel.findRoomByNumber(); break;
        case 8: hostel.showStatistics(); break;
        case 9: hostel.deleteRoom(); break;
        case 0:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Unknown option. Try again.\n";
        }
    }
}