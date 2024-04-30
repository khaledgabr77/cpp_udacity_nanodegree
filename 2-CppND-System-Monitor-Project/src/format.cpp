#include <string>
#include <sstream>
#include <iomanip>
#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    
  int HH, MM, SS;
  std::stringstream time;
  HH = (seconds / 3600) % 100; // Number of hours returns to 0 after 99
  MM = (seconds / 60) % 60;
  SS = seconds % 60;
  time << std::setfill('0') << std::setw(2) << HH << ":"
         << std::setfill('0') << std::setw(2) <<MM << ":"
         << std::setfill('0') << std::setw(2) << SS;
  return time.str();
}