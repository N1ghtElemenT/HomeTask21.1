#include <iostream>
#include "PhoneBook.h"
using namespace std;

PhoneBook::PhoneBook() : size(0), subscribers(nullptr) {}

PhoneBook::~PhoneBook() {
    for (int i = 0; i < size; ++i) {
        delete subscribers[i];
    }
    delete[] subscribers;
}

void PhoneBook::addSubscriber(const char* name, const char* phone, int d, int m, int y) {
    Subscriber** newSubscribers = new Subscriber * [size + 1];
    for (int i = 0; i < size; ++i) {
        newSubscribers[i] = subscribers[i];
    }
    newSubscribers[size] = new Subscriber(name, phone, d, m, y);
    delete[] subscribers;
    subscribers = newSubscribers;
    ++size;
}

void PhoneBook::removeSubscriber(const char* name) {
    for (int i = 0; i < size; ++i) {
        if (subscribers[i]->matchName(name)) {
            delete subscribers[i];
            for (int j = i; j < size - 1; ++j) {
                subscribers[j] = subscribers[j + 1];
            }
            --size;
            break;
        }
    }
}

void PhoneBook::searchSubscriber(const char* name) const {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (subscribers[i]->matchName(name)) {
            subscribers[i]->showSubscriber();
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Subscriber not found!" << std::endl;
    }
}

void PhoneBook::showAllSubscribers() const {
    if (size == 0) {
        std::cout << "Phone book is empty!" << std::endl;
    }
    else {
        for (int i = 0; i < size; ++i) {
            subscribers[i]->showSubscriber();
        }
    }
}

void PhoneBook::showCount() const {
    std::cout << "Total subscribers: " << Subscriber::getCount() << std::endl;
}