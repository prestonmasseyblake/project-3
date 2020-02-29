#include <iostream>
#include <string>
using namespace std;
#include "video.h"
//Constructor
Video::Video(string title, string url, string comment, float length, int rating)
{
        Video::title = title;
        Video::url = url;
        Video::comment = comment;
        Video::length = length;
        Video::rating  = rating;
}
//method used to print a video
//methods used by sort in main
//method to compare length
bool Video::longer(Video *other)
{
        return (length > other -> length);
}
//method to compare title alphanumericaly
bool Video::alphaNumeric(Video *other)
{
        return (title > other -> title);
}
//method to compare rating
bool Video::rate(Video *other)
{
        return (rating < other -> rating);
}
//method to print 
//void Video::print()
//{
//	       cout<<title<<", ";
//                cout<<url<<", ";
//                cout<<comment<<", ";
//                cout<<length<<", ";
//                for(int i=0;i<rating;i++)
//                {
//                cout<<"*";
//                }
//}

