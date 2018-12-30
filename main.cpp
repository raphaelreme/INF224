#include <iostream>
#include <memory>

#include "Table.h"

using namespace std;

//int main(int argc, const char* argv[])
int main()
{
    Table t = Table();

    GroupPtr g1 = t.createGroup("Fun");
    GroupPtr g2 = t.createGroup("Serious");

    MediaPtr p1 = t.createPhoto("P1", "./", 5, 5)

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

    g1->print(cout);
    g2->print(cout);

    /*
    g2.pop_back();

    g.print(cout);
    g2.print(cout);*/


    cout << endl;
    return 0;
}
