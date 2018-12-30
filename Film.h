#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>
#include "Video.h"

class Film : public Video {
  friend Table;
private:
  int numberOfChapters = 0;
  int * lengths = nullptr;

  void setLength(float length) override {
    Video::setLength(length);
  }

  void copyLengths(const int * lengths, int numberOfChapters) {
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

protected:
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

  public:
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

  //Operators
  Film& operator=(const Film& film) {
    Video::operator=(film);
    numberOfChapters = film.getNumberOfChapters(); //private ou pas ?
    copyLengths(film.getLengths(), numberOfChapters);
    return *this;
  }


  //Methods
  void print(std::ostream&) const override;
};

#endif
