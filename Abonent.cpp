#include <iostream>
#include "Abonent.h"
#include "Date.h"
using namespace std;

int Subscriber::count = 0;

Subscriber::Subscriber(const char* name, const char* phone, int d, int m, int y)
    : phoneNumber(phone), birthDate(d, m, y) {
    int nameLength = strlen(name) + 1;
    fullName = new char[nameLength];
    strcpy_s(fullName, nameLength, name);
    count++;
}

Subscriber::~Subscriber() {
    delete[] fullName;
    count--;
}

int Subscriber::getCount() {
    return count;
}

void Subscriber::showSubscriber() const {
    std::cout << "Name: " << fullName << ", Phone: " << phoneNumber << ", Date of Birth: ";
    birthDate.showDate();
    std::cout << std::endl;
}

bool Subscriber::matchName(const char* name) const {
    return strcmp(fullName, name) == 0;
}