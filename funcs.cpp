#include "funcs.h"

int minutesSinceMidnight(Time time) {
  return time.h*60 + time.m;
}

int minutesUntil(Time earlier, Time later) {
  return (later.h - earlier.h) * 60 + (later.m - earlier.m);
}

Time addMinutes(Time time0, int min) {
  int h = min / 60;
  int m = min % 60;
  Time result = {time0.h + h, time0.m + m};
  return result;
}
