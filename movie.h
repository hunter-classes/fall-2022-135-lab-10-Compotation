#pragma once

#include <string>

enum Genre {
  ACTION, COMEDY, DRAMA, ROMANCE, THRILLER
};

class Movie {
public:
  std::string title;
  Genre genre;
  int duration;

  friend bool operator==(const Movie &lhs, const Movie &rhs) {
    return lhs.title == rhs.title && lhs.genre == rhs.genre && lhs.duration == rhs.duration;
  }
};
