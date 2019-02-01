#ifndef TABLE_H
#define TABLE_H

#include <map>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>

#include "Media.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "tcpserver.h"

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

  /*remove a group or media from the table.
    If name match both a group and a media, it will only remove the group
  */
  void remove(std::string name);

  void display(std::string name, std::ostream& stream) const {
    find(name)->print(stream);
  }

  void play(std::string name) const {
    find(name)->read();
  }

  bool processRequest(cppu::TCPConnection& cnx, const std::string& request, std::string& response);

};
#endif
