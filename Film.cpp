#include "Film.h"

void Film::print(std::ostream& stream) const {
  stream << "Name : " << getName() << ", "
         << "Path : " << getPath() << ", "
         << "Length : " << getLength() << ", "
         << "Number of chapters : " << getNumberOfChapters() << std::endl;
  stream << "######Chapters :#######" << std::endl;
  for (int i=0; i<numberOfChapters; i++) {
    stream << "Chapter " << i << " : " << lengths[i] << std::endl;
  }
}
