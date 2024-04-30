
#include <cassert>
#include <iostream>

// TODO: Update the structure to initialize the member variables to a default of January 1, 2000
struct Date {
  int day;
  int month;
  int year;
};

int main() {
  Date date;
  assert(date.day == 1);
  assert(date.month == 1);
  assert(date.year == 2000);
  std::cout << date.day << "/" << date.month << "/" << date.year << "\n";
}
