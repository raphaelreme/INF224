#ifndef PHOTO_H
#define PHOTO_H

#include <string>
#include <iostream>
#include "Media.h"

/** @brief Define the photo model based on Media.
 *  A Photo has a longitude and a latitude.
 *
 *  See Table to create any Media.
 */
class Photo : public Media {
  friend Table;
private:
  float latitude = 0;
  float longitude = 0;

protected:
  Photo() {}
  Photo(std::string name, std::string path, float latitude,
      float longitude) : Media(name, path), latitude(latitude),
                         longitude(longitude) {}
public:
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

  void read() const override {
    system(("imagej " + getPath() + " &").c_str());
  }
};

#endif
