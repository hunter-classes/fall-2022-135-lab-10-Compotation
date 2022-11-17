#include "ostream"

class Time {
public:
  int h;
  int m;
  friend std::ostream& operator <<(std::ostream &os, Time const &t) {
    return os << t.h << ":" << t.m;
  };
};
