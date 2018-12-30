#ifndef TABLE_H
#define TABLE_H

#include <map>

#include "Media.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

typedef std::shared_ptr<Media> MediaPtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;
typedef std::shared_ptr<Group> GroupPtr;

class Table {
private:
  std::map<std::string, MediaPtr> medias;
  std::map<std::string, GroupPtr> groups;
public:
  Table() {}
  ~Table() {
    std::cout << "Delete a table" << std::endl;
  }

  PhotoPtr createPhoto(std::string name, std::string path, float latitude,
                       float longitude) {
    PhotoPtr p = (PhotoPtr) new Photo(name, path, latitude, longitude);
    medias[name] = p;
    return p;
  }

  VideoPtr createVideo(std::string name, std::string path, int length) {
    VideoPtr v = (VideoPtr) new Video(name, path, length);
    medias[name] = v;
    return v;
  }

  FilmPtr createFilm(std::string name, std::string path, int * lengths,
                     int numberOfChapters) {
    FilmPtr f = (FilmPtr) new Film(name, path, lengths, numberOfChapters);
    medias[name] = f;
    return f;
  }

  GroupPtr createGroup(std::string name) {
    GroupPtr g = (GroupPtr) new Group(name);
    groups[name] = g;
    return g;
  }

  MediaPtr find(std::string name) const {
    return medias.at(name);
  }

  void display(std::string name, std::ostream& stream) const {
    find(name)->print(stream);
  }

  void play(std::string name) const {
    find(name)->read();
  }

};
#endif
