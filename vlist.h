#ifndef VLIST_H
#define VLIST_H

#include "video.h"
#include <iostream>

class Vlist {
	public:
		Vlist() { m_head = nullptr; }
		void length();
		void insert(Video *newvideo);
		void print();
		void lookup(string title);
		void remove(string title);
	private:
	class Node {
	public:
		Node(Video *video, Node *next)
		{m_video = video; m_next = next;}		
		Video *m_video;
		Node *m_next;
};
		Node *m_head;
};
#endif
