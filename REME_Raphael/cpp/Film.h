#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>
#include "Video.h"

/** @brief Define the film model based on Media and Video.
 *  A Film have chapters and a length for each one. its length is the sum of them.
 *
 *  See Table to create any Media.
 *
 *  Note : copy is also only possible threw Table.
 */
class Film : public Video {
  friend Table;
private:
  int numberOfChapters = 0;
  int * lengths = nullptr;

  /*
   * User should not use this function anymore.
   */
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
    numberOfChapters = film.getNumberOfChapters();
    copyLengths(film.getLengths(), numberOfChapters);
  }

  //Operators
  Film& operator=(const Film& film) {
    Video::operator=(film);
    numberOfChapters = film.getNumberOfChapters();
    copyLengths(film.getLengths(), numberOfChapters);
    return *this;
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

  //Methods
  void print(std::ostream&) const override;
};

#endif
