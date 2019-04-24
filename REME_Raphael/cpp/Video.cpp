#include "Video.h"

void Video::print(std::ostream& stream) const {
  stream << "Name : " << getName() << ", "
         << "Path : " << getPath() << ", "
         << "Length : " << getLength() << std::endl;
}
