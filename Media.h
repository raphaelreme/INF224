#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>

/** @brief define the base class for media.
 *  A media has name and a path
 */
class Media {
private:
  std::string name;
  std::string path;
public:
  Media() {}
  Media(std::string name, std::string path) : name(name), path(path) {}
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

};

#endif
