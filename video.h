#ifndef VIDEO
#define VIDEO
#include <iostream>
#include <string>
using namespace std;
//creating class videos
class Video
{
        public:
                //constructor
                Video(string title, string url, string comment, float length, int rating);
                //method for comparing length of videos
                bool longer(Video *other);
                //method for comparing rating of videos
                bool rate(Video *other);
                //method for comparing titles alphanumericaly
                bool alphaNumeric(Video *other);
                //Video data fields
                string title;
                string url;
                string comment;
                float length;
                int rating;
};

#endif

