#include "Photo.h"

void Photo::print(std::ostream& stream) const {
  stream << "Name : " << getName() << ", "
         << "Path : " << getPath() << ", "
         << "Latitude : " << getLatitude() << ", "
         << "Longitude : " << getLongitude() << std::endl;
}
