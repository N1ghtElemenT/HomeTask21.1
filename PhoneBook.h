#pragma once
#include <iostream>
#include "Abonent.h"

class PhoneBook {
private:
    Subscriber** subscribers;
    int size;

public:
    PhoneBook();
    ~PhoneBook();

    void addSubscriber(const char* name, const char* phone, int d, int m, int y);
    void removeSubscriber(const char* name);
    void searchSubscriber(const char* name) const;
    void showAllSubscribers() const;
    void showCount() const;
};
