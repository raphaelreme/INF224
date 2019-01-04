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

bool delete_media(MediaPtr med) {
  return (med->getName() == name);
}


class Table {
private:
  std::map<std::string, MediaPtr> medias;
  std::map<std::string, GroupPtr> groups;
public:
  Table() {}
  ~Table() {
    std::cout << "Delete a table" << std::endl;
  }

  //Generation of Medias/Groups
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



  //Methods
  MediaPtr find(std::string name) const {
    return medias.at(name);
  }

  GroupPtr findGroup(std::string name) const {
    return groups.at(name);
  }

  void delete(std::string name) {
    auto it_g = groups.find(name);
    if (it_g != groups.end()) {
      groups.erase(it_g);
      return;
    }

    //If the name doesn't fit a group, it should fit a media.
    auto it_m = medias.find(name);
    if (it_m != medias.end()) {
      for (auto& elt : groups) {
        GroupPtr group = elt.second;
        group->remove_if(delete_media);
      }

      medias.erase(it);
      return;
    }
  }

  void display(std::string name, std::ostream& stream) const {
    find(name)->print(stream);
  }

  void play(std::string name) const {
    find(name)->read();
  }

};
#endif
