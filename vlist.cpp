#include "vlist.h"
#include "video.h"
#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
void Vlist::print()
{
	Node * ptr = m_head;
	while(ptr!=nullptr)
	{
		cout<<ptr->m_video->title<<", ";
		cout<<ptr->m_video->url<<", ";
		cout<<ptr->m_video->comment<<", ";
		cout<<ptr->m_video->length<<", ";
		for(int i=0;i<ptr->m_video->rating;i++)
		{
		cout<<"*";
		}
		ptr=ptr->m_next;
		cout<<"\n";
	}
}
///////////////////////////////////////////////////////////////////////////////
void Vlist::insert(Video *newvideo) 
{
bool check = false;	
if (m_head == NULL || m_head->m_video->title > newvideo->title) 
{
		m_head = new Node(newvideo, m_head);
		check=true;
}
else{
Node *ptr = m_head;
while(ptr->m_next != NULL && ptr->m_next->m_video->title < newvideo->title)
{
ptr=ptr->m_next;
}
ptr->m_next= new Node(newvideo,ptr->m_next);
check=true;
}
if(check==false)
cerr<<"Could not insert video <"<<newvideo->title<<"> not in the list."<<endl;
}
////////////////////////////////////////////////////////////////////////////////
//Lookup a video by title and print it
void Vlist::lookup(string title)
{
bool check =false; 
Node * ptr=m_head;
while(ptr!=NULL)
{
if(ptr->m_video->title==title)
{
		cout<<ptr->m_video->title<<", ";
                cout<<ptr->m_video->url<<", ";
                cout<<ptr->m_video->comment<<", ";
                cout<<ptr->m_video->length<<", ";
		for(int i=0;i<ptr->m_video->rating;i++)
                {
                cout<<"*";
                }
check=true;
}
ptr=ptr->m_next;
}
if(check==true)
cout<<"\n";
if(check==false)
{
cerr<<"Title <"<<title<<"> not in list."<<endl;
}
}
///////////////////////////////////////////////////////////////////////////////
//Output the number of videos in the list
void Vlist::length()
{
int amount=0;
Node * ptr = m_head;
while(ptr!=NULL)
{
amount++;
ptr=ptr->m_next;
}
cout<<amount<<endl;
}
///////////////////////////////////////////////////////////////////////////////
//Remove a video from the list by title
void Vlist::remove(string title)
{
bool check = false;
if(m_head != nullptr){
if(m_head->m_video->title==title){
Node* tmp = m_head;
m_head = m_head->m_next;
delete tmp ;
check = true;
}
else
{
Node * node = m_head;
while(node->m_next != NULL && node->m_next->m_video->title != title)
{
node = node->m_next;
}
if(node->m_next != NULL)
{
Node *tmp = node->m_next;
node->m_next = node->m_next->m_next;
delete tmp;
check=true;
}
}
}
if(check==false)
{
cerr<<"Title <"<<title<<"> not in list, could not delete."<<endl;
}
}
