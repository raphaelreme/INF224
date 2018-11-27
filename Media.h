#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <iostream>


class Media {
private:
  std::string name;
  std::string file;
public:
  Media() {}
  Media(std::string name, std::string file) : name(name), file(file) {}
  ~Media() {}

  std::string getName() const {
    return name;
  }

  std::string getFile() const {
    return file;
  }

  void setName(std::string name) {
    this->name = name;
  }

  void setFile(std::string file) {
    this->file = file;
  }

  void print(std::ostream&);

};

#endif
