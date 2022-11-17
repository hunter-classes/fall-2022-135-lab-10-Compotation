#pragma once
#include "ostream"

class Time {
public:
  int h;
  int m;
  friend std::ostream& operator <<(std::ostream &os, Time const &t) {
    return os << t.h << ":" << (t.m == 0 ? "00" : std::to_string(t.m));
  };
  friend bool operator ==(const Time& lhs, const Time& rhs) {
    return lhs.h == rhs.h && lhs.m == rhs.m;
  }
};
