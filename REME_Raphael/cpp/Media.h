#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>

class Table;

/** @brief Define the base class for media.
 *  A media has name and a path.
 *
 *  See Table to create any Media.
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

  /*
   * Print the attribute of the object on the ostream.
   */
  virtual void print(std::ostream&) const;

  /*
   * Play the media with the appropriate tool.
   */
  virtual void read() const = 0;
};

#endif
