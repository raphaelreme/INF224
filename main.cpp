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

    MediaPtr p1 = (MediaPtr) new Photo("P1", "./", 5, 5);
    g.push_back(p1);

    g.push_back((MediaPtr) new Video("V1", "./", 10));

    int lengths[] = {1,2,3,2,1};
    g.push_back((MediaPtr) new Film("F1","./",lengths, 5));

    g2.push_back(p1);

    g.print(cout);
    g2.print(cout);

    g.pop_back();
    g.pop_back();
    g.pop_back();

    cout << endl;

    g2.pop_back();

    g.print(cout);
    g2.print(cout);


    cout << endl;
    return 0;
}
