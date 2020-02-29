#include <iostream>
#include <string>
using namespace std;
#include "vlist.h"
#include "video.h"
int main()
{
	Video* video;
	Vlist list;
	string title, url, comment, command;
	float length = 0;
	int rating = 0;
while(getline(cin,command))
{	
	if(command=="insert")
	{
		getline(cin,title);
		getline(cin,url);
		getline(cin,comment);
		cin>>length;
		cin>>rating;
		cin.ignore();
		video = new Video(title, url, comment, length, rating);
		list.insert(video); 
	}
	if(command=="print")
	{
	list.print();
	}
	if(command=="length")
	{
	list.length();
	}
	if(command=="lookup")
	{
	getline(cin,title);
	list.lookup(title);
	}
	if(command=="remove"){
	getline(cin,title);
	list.remove(title);
	}
	else if(command!="insert" && command!="length" && command!="lookup" && command!="remove" && command!="print"){
	cerr<<"<"<<command<<"> is not a legal command, giving up."<<endl;
	return 1;
}
}
}
