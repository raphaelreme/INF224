#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>

class Table;

/** @brief define the base class for media.
 *  A media has name and a path
 */
class Media {
  friend Table;
private:
  std::string name;
  std::string path;

protected:
  Media() {}
  Media(std::string name, std::string path) : name(name), path(path) {}

public:
  virtual ~Media() {
    std::cout << "Delete a media" << std::endl;
  }

  std::string getName() const {
    return name;
  }

  std::string getPath() const {
    return path;
  }

  void setName(std::string name) {
    this->name = name;
  }

  void setPath(std::string path) {
    this->path = path;
  }

  virtual void print(std::ostream&) const;

  virtual void read() const = 0;


};

#endif
