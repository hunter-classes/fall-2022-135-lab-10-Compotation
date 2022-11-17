#pragma once

#include "movie.h"
#include "time.h"

class TimeSlot {
public:
  Movie movie;
  Time startTime;

  friend bool operator==(const TimeSlot &lhs, const TimeSlot &rhs) {
    return lhs.movie == rhs.movie && lhs.startTime == rhs.startTime;
  }
};
