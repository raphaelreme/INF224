#ifndef GROUP_H
#define GROUP_H

#include <memory>

#include <list>
#include "Media.h"


class Group : public std::list<std::shared_ptr<Media>> {
  friend Table;
private:
  std::string name;

  Group() {}
  Group(std::string name) : name(name) {}
  
public:
  ~Group() {
    std::cout << "Delete a group" << std::endl;
  }


  std::string getName() const {
    return name;
  }

  void print(std::ostream&) const;
};


#endif
