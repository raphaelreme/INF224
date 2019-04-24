#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
#include "Media.h"

/** @brief Define the video model based on Media.
 *  A Video only has a length more.
 *
 *  See Table to create any Media.
 */
class Video : public Media {
  friend Table;
private:
  int length = 0;

protected:
  Video() {}
  Video(std::string name, std::string path, int length) :
          Media(name, path), length(length) {}

public:
  ~Video() {
    std::cout << "Delete a video" << std::endl;
  }

  int getLength() const {
    return length;
  }

  virtual void setLength(float length) {
    this->length = length;
  }

  virtual void print(std::ostream&) const override;

  void read() const override {
    system(("mpv " + getPath() + " &").c_str());
  }
};

#endif
