#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
#include "Media.h"


class Video : public Media {
private:
  int length = 0;

public:
  Video() {}
  Video(std::string name, std::string path, int length) :
          Media(name, path), length(length) {}

  ~Video() {
    std::cout << "Delete a video" << std::endl;
  }

  int getLength() const {
    return length;
  }

  void setLength(float length) {
    this->length = length;
  }

  void print(std::ostream&) const override;

  void read() const override {
    system(("mpv " + getPath() + " &").c_str());
  }
};

#endif
