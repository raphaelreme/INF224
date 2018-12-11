//
// main.cpp
// Created on 27/10/2018
//

#include <iostream>

#include "Media.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"

using namespace std;

//int main(int argc, const char* argv[])
int main()
{
    /*Media * medias[10];
    int count = 0;
    medias[count++] = new Photo("photo", "0",8,8);
    medias[count++] = new Photo("photo", "1",8,8);
    medias[count++] = new Video("video", "2", 7);
    medias[count++] = new Video("video", "3", 7);
    medias[count++] = new Photo("photo", "4",8,8);
    medias[count++] = new Video("video", "5", 7);
    medias[count++] = new Photo("photo", "6",8,8);
    medias[count++] = new Video("video", "7", 7);
    medias[count++] = new Video("video", "8", 7);
    medias[count++] = new Video("video", "9", 7);

    for (int i = 0; i<10; i++){
      medias[i]->print(coutFilm * f1 = new Film("film", "0", 5, lengths););
      delete medias[i];
    }*/
    int * lengths = new int [5] {1,2,3,2,1};

    Video * m1 = new Video("Media1", "./", 3);
    Film * f1 = new Film("film","./", lengths, 5);
    Media * f2 = new Film();


    f1->print(cout);

    //*((Film *) f2) = *f1;
    f2->setName("Film2");


    f2->print(cout);

    cout << endl << endl;



    delete [] lengths;
    delete f1;
    delete f2;
    return 0;
}
