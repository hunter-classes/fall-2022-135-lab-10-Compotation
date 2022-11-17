#include "funcs.h"

int minutesSinceMidnight(Time time) {
  return time.h*60 + time.m;
}

int minutesUntil(Time earlier, Time later) {
  return (later.h - earlier.h) * 60 + (later.m - earlier.m);
}
