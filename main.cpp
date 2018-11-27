//
// main.cpp
// Created on 27/10/2018
//

#include <iostream>

#include "Media.h"
#include "Photo.h"
#include "Video.h"

using namespace std;

int main(int argc, const char* argv[])
{
    Media * m1 = new Media("media", "test");
    Media * m2 = new Photo("photo", "test", 3, 3);
    Media * m3 = new Video("video", "test", 7);
    m1->print(cout);
    m2->print(cout);
    m3->print(cout);

    delete m1;
    delete m2;
    delete m3;
    return 0;
}
