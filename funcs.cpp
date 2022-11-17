#include "funcs.h"

int minutesSinceMidnight(Time time) {
  return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later) {
  return (later.h - earlier.h) * 60 + (later.m - earlier.m);
}

Time addMinutes(Time time0, int min) {
  return toTime(minutesSinceMidnight(time0) + min);
}

Time toTime(int min) {
  return {min / 60, min % 60};
}

std::string getTimeSlot(const TimeSlot &ts) {
  return " [starts at " + getTime(ts.startTime) + ", ends by " + getTime(addMinutes(ts.startTime, ts.movie.duration));
}

std::string getMovie(const Movie &mv) {
  std::string g;
  switch (mv.genre) {
    case ACTION   :
      g = "ACTION";
      break;
    case COMEDY   :
      g = "COMEDY";
      break;
    case DRAMA    :
      g = "DRAMA";
      break;
    case ROMANCE  :
      g = "ROMANCE";
      break;
    case THRILLER :
      g = "THRILLER";
      break;
  }
  return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}

std::string getTime(Time time) {
  return std::to_string(time.h) + ":" + std::to_string(time.m);
}