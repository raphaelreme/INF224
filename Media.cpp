#include "Media.h"

void Media::print(std::ostream& stream){
  stream << "Name : " << getName()
         << "File : " << getFile() << std::endl;
}
