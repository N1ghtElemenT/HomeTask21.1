#pragma once
#include <iostream>
#include "Date.h"

class Subscriber {
private:
    static int count;
    char* fullName;
    const char* phoneNumber;
    Date birthDate;

public:
    Subscriber(const char* name, const char* phone, int d, int m, int y);
    ~Subscriber();

    static int getCount();
    void showSubscriber() const;
    bool matchName(const char* name) const;
};

