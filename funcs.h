#pragma once

#include "time.h"
#include "timeslot.h"

int minutesSinceMidnight(Time time);

int minutesUntil(Time earlier, Time later);

Time addMinutes(Time time0, int min);

Time toTime(int min);

std::string getTimeSlot(const TimeSlot &ts);

std::string getMovie(const Movie &mv);

std::string getTime(Time t);
