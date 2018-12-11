#ifndef GROUP_H
#define GROUP_H

#include <memory>

#include <list>
#include "Media.h"


class Group : public std::list<std::shared_ptr<Media>> {
private:
  std::string name;
public:
  Group() {}
  Group(std::string name) : name(name) {}

  ~Group() {
    std::cout << "Delete a film" << std::endl;
  }


  std::string getName() const {
    return name;
  }

  void print(std::ostream&) const;
};


#endif
