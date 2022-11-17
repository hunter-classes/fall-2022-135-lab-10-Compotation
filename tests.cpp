#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("task a: minutes since midnight") {
  Time t0120 = {1, 20};
  CHECK_EQ(minutesSinceMidnight(t0120), 80);
  Time t1349 = {13, 49};
  CHECK_EQ(minutesSinceMidnight(t1349), 829);
  Time t0000 = {0, 0};
  CHECK_EQ(minutesSinceMidnight(t0000), 0);
}

TEST_CASE("task a: minutes until") {
  Time t1500 = {15, 0};
  Time t1430 = {14, 30};
  CHECK_EQ(minutesUntil(t1430, t1500), 30);

  Time t1340 = {13, 40};
  Time t1030 = {10, 30};
  CHECK_EQ(minutesUntil(t1030, t1340), 190);
}

TEST_CASE("task b: add minutes") {
  Time t0810 = {8, 10};
  Time t0810Result = {9, 25};
  CHECK_EQ(addMinutes(t0810, 75), t0810Result);

  Time t1320 = {13, 20};
  Time t1320Result = {13, 35};
  CHECK_EQ(addMinutes(t1320, 15), t1320Result);

  Time t1111 = {11, 11};
  CHECK_EQ(addMinutes({9, 15}, 116), t1111);
}

TEST_CASE("task c") {
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  Movie wakanda = {"Black Panther: Wakanda Forever", ACTION, 161};

  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};
  TimeSlot timeSlot1 = {wakanda, {8, 0}};
  TimeSlot timeSlot2 = {wakanda, {20, 30}};

  CHECK_EQ(getTimeSlot(morning), "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]");
  CHECK_EQ(getTimeSlot(daytime), "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]");
  CHECK_EQ(getTimeSlot(evening), "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]");
  CHECK_EQ(getTimeSlot(timeSlot1), "Black Panther: Wakanda Forever ACTION (161 min) [starts at 8:0, ends by 10:41]");
  CHECK_EQ(getTimeSlot(timeSlot2), "Black Panther: Wakanda Forever ACTION (161 min) [starts at 20:30, ends by 23:11]");
}
