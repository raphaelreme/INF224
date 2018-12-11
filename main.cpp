#include <iostream>
#include <memory>

#include "Media.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

using namespace std;

using MediaPtr = std::shared_ptr<Media>;

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
    Group g = Group("Group1");
    Group g2 = Group("Group2");

    Photo * p1 = new Photo("P1", "./", 5, 5);
    g.push_back(p1);

    Video * v1 = new Video("V1", "./", 10);
    g.push_back(v1);

    int * lengths = int [5] {1,2,3,2,1};
    Film * f1 = new Film("F1","./",lengths, 5);
    g.push_back(f1);

    g2.push_back(v1);

    g.print(cout);
    g2.print(cout);

    delete p1;
    delete v1;
    delete f1;

    cout << endl;
    return 0;
}
