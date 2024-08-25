#include <iostream>
#include "MemoryManagementUnit.h"
using namespace std;

void displayMenu() {
    std::cout << "Memory Management Simulator\n";
    std::cout << "1. Allocate Memory\n";
    std::cout << "2. Deallocate Memory\n";
    std::cout << "3. View Memory\n";
    std::cout << "4. View Statistics\n";
    std::cout << "5. Exit\n";
}

int main() {
    MemoryManagementUnit mmu(1000); // Initialize memory with 1000 units
    int choice;
    size_t size, address;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter size to allocate: ";
            std::cin >> size;
            mmu.allocate(size);
            break;
        case 2:
            std::cout << "Enter address to deallocate: ";
            std::cin >> address;
            mmu.deallocate(address);
            break;
        case 3:
            mmu.visualize();
            break;
        case 4:
            mmu.printStatistics();
            break;
        case 5:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
