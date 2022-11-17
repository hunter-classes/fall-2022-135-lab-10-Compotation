#include "funcs.h"
#include <iostream>

int main() {
  Time t0230 = {2, 30};
  std::cout << minutesSinceMidnight(t0230) << "\n";
  Time t1340 = {13, 40};
  Time t1030 = {10, 30};
  std::cout << t1030 << " to " << t1340 << " is " << minutesUntil(t1030, t1340) << " minutes" << "\n";

  Time t0810 = {8, 10};
  std::cout << t0810 << " + 75 minutes is: " << addMinutes(t0810, 75) << "\n";
  return 0;
}