#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::showDate() const {
    std::cout << day << "/" << month << "/" << year;
}