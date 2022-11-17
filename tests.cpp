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
