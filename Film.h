#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>
#include "Video.h"


class Film : public Video {
private:
  int numberOfChapters = 0;
  int * lengths = nullptr;

  void setLength(float length) override {
    Video::setLength(length);
  }

public:
  Film() {}
  Film(std::string name, std::string path, int numberOfChapters, int * lengths) :
          Video(name, path, 0), numberOfChapters(numberOfChapters)
  {
    int length = 0;
    this->lengths = new int [numberOfChapters];
    for (int i = 0; i<numberOfChapters; i++) {
      length += lengths[i];
      (this->lengths)[i] = lengths[i];
    }
    setLength(length);
  }

  ~Film() {
    delete [] lengths;
    std::cout << "Delete a film" << std::endl;
  }

  const int * getLengths() const {
    return lengths;
  }

  int getNumberOfChapters() const {
    return numberOfChapters;
  }

  void setLengths(int numberOfChapters, int * lengths) {
    int length = 0;
    delete [] this->lengths;
    this->lengths = new int [numberOfChapters];
    for (int i = 0; i<numberOfChapters; i++) {
      length += lengths[i];
      (this->lengths)[i] = lengths[i];
    }
    setLength(length);
  }

  void print(std::ostream&) const override;

  void read() const override {
    system(("mpv " + getPath() + " &").c_str());
  }
};

#endif
