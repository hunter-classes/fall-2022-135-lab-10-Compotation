#include "funcs.h"

#include <utility>

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
  return getMovie(ts.movie) + " [starts at " + getTime(ts.startTime) + ", ends by " +
         getTime(addMinutes(ts.startTime, ts.movie.duration)) + "]";
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
  return std::to_string(time.h) + ":" + (time.m == 0 ? "00" : std::to_string(time.m));
}

TimeSlot scheduleAfter(const TimeSlot &ts, Movie nextMovie) {
  TimeSlot result = {std::move(nextMovie), addMinutes(ts.startTime, ts.movie.duration)};
  return result;
}

bool timeOverlap(const TimeSlot &ts1, const TimeSlot &ts2) {
  if (minutesSinceMidnight(ts1.startTime) > minutesSinceMidnight(ts2.startTime)) {
    return minutesUntil(addMinutes(ts2.startTime, ts2.movie.duration), ts1.startTime) < 0;
  }
  return minutesUntil(addMinutes(ts1.startTime, ts1.movie.duration), ts2.startTime) < 0;
}
