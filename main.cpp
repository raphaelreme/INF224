//
// main.cpp
// Created on 27/10/2018
//

#include <iostream>

#include "Media.h"

using namespace std;

int main(int argc, const char* argv[])
{
    Media * m1 = new Media();
    Media * m2 = new Media("m2", "test");
    Media * m3 = new Media("m3", "test");
    m1->print(cout);
    m2->print(cout);
    m3->print(cout);
    return 0;
}
