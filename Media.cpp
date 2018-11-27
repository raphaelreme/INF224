#include "Media.h"

Circle::print(std::ostream& stream){
  stream << "Name : " << getName()
         << "File : " << getFile() << std::endl;
}
