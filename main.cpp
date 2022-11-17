#include "funcs.h"
#include <iostream>

int main() {
  Time t0230 = {2, 30};
  std::cout << t0230 << " is " << minutesSinceMidnight(t0230) << " minutes after midnight" << "\n";
  Time t1340 = {13, 40};
  Time t1030 = {10, 30};
  std::cout << t1030 << " to " << t1340 << " is " << minutesUntil(t1030, t1340) << " minutes" << "\n";

  Time t0810 = {8, 10};
  std::cout << t0810 << " + 75 minutes is: " << addMinutes(t0810, 75) << "\n";


  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie wakanda = {"Black Panther: Wakanda Forever", ACTION, 161};

  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};
  TimeSlot timeSlot1 = {wakanda, {8, 0}};
  TimeSlot timeSlot2 = {wakanda, {20, 30}};

  std::cout << getTimeSlot(morning) << "\n" << getTimeSlot(daytime) << "\n" << getTimeSlot(evening) << "\n"
            << getTimeSlot(timeSlot1) << "\n" << getTimeSlot(timeSlot2) << "\n\n";

  std::cout << "schedule Wakanda after: " << getTimeSlot(morning) << "\n"
            << getTimeSlot(scheduleAfter(morning, wakanda)) << "\n";

  std::cout << "is there overlap between timeSlot1 and morning: " << timeOverlap(timeSlot1, morning) << "\n";
  return 0;
}