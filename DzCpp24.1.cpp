#include <iostream>
#include "Abonent.h"
#include "Date.h"
#include "PhoneBook.h"
using namespace std;

int main() {
    PhoneBook phoneBook;

    int choice;
    char name[100], phone[15];
    int day, month, year;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1 - Add subscriber\n";
        std::cout << "2 - Remove subscriber\n";
        std::cout << "3 - Search subscriber by name\n";
        std::cout << "4 - Show all subscribers\n";
        std::cout << "5 - Show subscriber count\n";
        std::cout << "0 - Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore(100, '\n');

        switch (choice) {
        case 1:
            std::cout << "Enter full name: ";
            std::cin.getline(name, 100);
            std::cout << "Enter phone number: ";
            std::cin.getline(phone, 15);
            std::cout << "Enter birth date (day month year): ";
            std::cin >> day >> month >> year;
            std::cin.ignore(100, '\n');
            phoneBook.addSubscriber(name, phone, day, month, year);
            break;

        case 2:
            std::cout << "Enter full name to remove: ";
            std::cin.getline(name, 100);
            phoneBook.removeSubscriber(name);
            break;

        case 3:
            std::cout << "Enter full name to search: ";
            std::cin.getline(name, 100);
            phoneBook.searchSubscriber(name);
            break;

        case 4:
            phoneBook.showAllSubscribers();
            break;

        case 5:
            phoneBook.showCount();
            break;

        case 0:
            std::cout << "Exiting program...\n";
            return 0;

        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    }
    return 0;
}