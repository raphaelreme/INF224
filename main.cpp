#include <iostream>
#include <memory>

#include "tcpserver.h"
#include "Table.h"

using namespace std;
using namespace cppu;

const int PORT = 3331;

#ifdef OLD_VERSION
//int main(int argc, const char* argv[])
int main()
{
    Table t = Table();

    GroupPtr g1 = t.createGroup("Fun");
    GroupPtr g2 = t.createGroup("Serious");

    MediaPtr p1 = t.createPhoto("P1", "./", 5, 5);

    g1->push_back(p1);
    g2->push_back(p1);


    g1->push_back((MediaPtr) t.createVideo("V1", "./", 10));

    int lengths[] = {1,2,3,2,1};
    g1->push_back((MediaPtr) t.createFilm("F1","./",lengths, 5));

    g1->print(cout);
    g2->print(cout);

    g1.reset();
    g2.reset();

    /*
    g.pop_back();
    g.pop_back();
    g.pop_back();*/

    cout << endl;

    t.remove("F1");

    ((Photo*) t.find("P1").get())->setLatitude(14);
    t.find("V1")->setName("V2");
    t.findGroup("Fun")->print(cout);
    t.findGroup("Serious")->print(cout);
    /*
    g2.pop_back();

    g.print(cout);
    g2.print(cout);*/


    cout << endl;
    return 0;
}
#endif

int main()
{
  // cree le TCPServer
  shared_ptr<TCPServer> server(new TCPServer());

  // cree l'objet qui gère les données
  shared_ptr<Table> table(new Table());
  GroupPtr g1 = table->createGroup("Fun");
  GroupPtr g2 = table->createGroup("Serious");

  MediaPtr p1 = table->createPhoto("P1", "./", 5, 5);

  g1->push_back(p1);
  g2->push_back(p1);


  g1->push_back((MediaPtr) table->createVideo("V1", "./", 10));

  int lengths[] = {1,2,3,2,1};
  g1->push_back((MediaPtr) table->createFilm("F1","./",lengths, 5));

  g1.reset();
  g2.reset();

  // le serveur appelera cette méthode chaque fois qu'il y a une requête
  server->setCallback(*table, &Table::processRequest);

  // lance la boucle infinie du serveur
  cout << "Starting Server on port " << PORT << endl;
  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    cerr << "Could not start Server on port " << PORT << endl;
    return 1;
  }

  return 0;
}
