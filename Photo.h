#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <iostream>
#include "Media.h"


class Photo : public Media {
private:
  float latitude = 0;
  float longitude = 0;

public:
  Photo() {}
  Photo(std::string name, std::string path, float latitude,
      float longitude) : Media(name, path), latitude(latitude),
                         longitude(longitude) {}

  ~Photo() {
    std::cout << "Delete a photo" << std::endl;
  }

  float getLatitude() const {
    return latitude;
  }

  float getLongitude() const {
    return longitude;
  }

  void setLatitude(float latitude) {
    this->latitude = latitude;
  }

  void setLongitude(float longitude) {
    this->longitude = longitude;
  }

  void print(std::ostream&) const override;
};

#endif
