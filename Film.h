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

  void copyLengths(int * lengths, int numberOfChapters) {
    if (!lengths) {
      this->lengths = nullptr;
      setLength(0);
      return;
    }

    int length = 0;
    this->lengths = new int [numberOfChapters];
    for (int i = 0; i<numberOfChapters; i++) {
      length += lengths[i];
      (this->lengths)[i] = lengths[i];
    }
    setLength(length);
  }

public:
  Film() {}
  Film(std::string name, std::string path, int * lengths, int numberOfChapters) :
          Video(name, path, 0), numberOfChapters(numberOfChapters)
  {
    copyLengths(lengths, numberOfChapters);
  }

  Film(const Film& film) : Video(film) {
    numberOfChapters = film.numberOfChapters; //private ou pas ?
    copyLengths(film.lengths, numberOfChapters);
  }

  ~Film() {
    delete [] lengths; //What if nullptr ?
    std::cout << "Delete a film" << std::endl;
  }

  //Getters
  const int * getLengths() const {
    return lengths;
  }

  int getNumberOfChapters() const {
    return numberOfChapters;
  }

  //Setters
  void setLengths(int numberOfChapters, int * lengths) {
    delete [] this->lengths; //what if null ptr ?
    copyLengths(lengths, numberOfChapters);
  }


  Film& operator=(const Film& film) {
    Video::operator=(film);
    numberOfChapters = film.numberOfChapters; //private ou pas ?
    copyLengths(film.lengths, numberOfChapters);
    return *this;
  }




  void print(std::ostream&) const override;

  void read() const override {
    system(("mpv " + getPath() + " &").c_str());
  }
};

#endif
