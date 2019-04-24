#include "Group.h"

void Group::print(std::ostream& stream) const {
  int i = 1;
  stream << name << "'s elements :" << std::endl;
  for (auto & it : *this) {
    stream << i++ << "th element :" << std::endl;
    it->print(stream);
    stream << std::endl;
  }
}
