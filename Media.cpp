#include "Media.h"

void Media::print(std::ostream& stream) const {
  stream << "Name : " << getName() << ", "
         << "Path : " << getPath() << std::endl;
}
