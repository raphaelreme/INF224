#include <iostream>
#include <sstream>
#include <exception>

#include "Table.h"
using namespace cppu;
using namespace std;

void Table::remove(string name) {
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
      group->remove_if([name](MediaPtr m) {return m->getName() == name;});
    }

    medias.erase(it_m);
    return;
  }
}


bool Table::processRequest(TCPConnection& cnx, const string& request, string& response) {
  cerr << "\nRequest: '" << request << "'" << endl;

  stringstream ss(request);

  string commande;
  string argument;

  ss >> commande;
  if (commande == "findm") {
    ss >> argument;
    MediaPtr media;

    TCPLock lock(cnx);

    try {
      media = find(argument);
    } catch (out_of_range const& e) {
      cerr << "Erreur : " << e.what() << endl;
      response = "Not found : " + argument;
      return true;
    }
    stringbuf buffer = stringbuf();
    ostream os(&buffer);
    if (media.get()) {
      media->print(os);
      string s = buffer.str();
      for (uint i = 0; i<s.length(); i++)
        if (s.at(i) == "\n"[0] or s.at(i) == "\r"[0])
          s.replace(i, 1, " ");
      response = "Found " + argument + " : " + s;
    }
    return true;
  }

  if (commande == "findg") {
    ss >> argument;
    GroupPtr group;

    TCPLock lock(cnx);

    try {
      group = findGroup(argument);
    } catch (out_of_range const& e) {
      cerr << "Erreur : " << e.what() << endl;
      response = "Not found : " + argument;
      return true;
    }
    stringbuf buffer = stringbuf();
    ostream os(&buffer);
    if (group.get()) {
      group->print(os);
      string s = buffer.str();
      for (uint i = 0; i<s.length(); i++)
        if (s.at(i) == "\n"[0] or s.at(i) == "\r"[0])
          s.replace(i, 1, " ");
      response = "Found " + argument + " : " + s;
    }
    return true;
  }

  if (commande == "play") {
    ss >> argument;
    MediaPtr media;

    TCPLock lock(cnx);

    try {
      media = find(argument);
    } catch (out_of_range const& e) {
      cerr << "Erreur : " << e.what() << endl;
      response = "Not found : " + argument;
      return true;
    }
    media->read();
    response = "Play " + argument;
    return true;
  }

  response = "Invalid command: " + commande;
  cerr << "response: " << response << endl;

  // renvoyer false si on veut clore la connexion avec le client
  return true;
}
