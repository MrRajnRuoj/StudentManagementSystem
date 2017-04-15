
#ifndef _STRUCTUREDDATA_H_
#define _STRUCTUREDDATA_H_
#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node* pNext;
	Node* pPrev;
};
template <class T>
struct List
{
	Node<T>* pHead;
	Node<T>* pTail;
};

struct User
{
	string username;
	string fullName;
	string email;
	string mobilePhone;
	int type;
	string password;
	string classOfSt;
};
struct Student
{
	string ID;
	string fullName;
	float midtermScore;
	float labScore;
	float finalScore;
	bool week[20];
};
struct Courses
{
	string code;
	int year;
	short semaster;
	string name;
	string lecturerUsername;
	string start;
	string end;
	string from;
	string to;
	List<Student> lStd;
};
struct Data
{
	List<User> lUser;
	List<Courses> lCourses;
	
};

/*
* Functions of Doubly Linked List for all data type
*/

template <class T>
void init(List<T> &l)
{
	l.pHead = l.pTail = NULL;
}
template <class T>
Node<T>* Getnode(T x)
{
	Node<T>* p = new Node<T>;
	if (p == NULL)
	{
		cout << "No data" << endl;
		return NULL;
	}

	p->data = x;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}
template <class T>
void addHead(List<T> &l, T x)
{
	Node<T>* p = Getnode(x);
	if (l.pHead == NULL && l.pTail == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pHead = p;
	}
}
template <class T>
void removeK(List<T> &l, Node<T>* &x)
{
	if (x->pNext != NULL)
		x->pNext->pPrev = x->pPrev;
	if (x->pPrev != NULL)
		x->pPrev->pNext = x->pNext;
	if (l.pHead == x)
		l.pHead = l.pHead->pNext;
	if (l.pTail == x)
		l.pTail = l.pTail->pPrev;
	delete x;
}
template <class T>
bool checkempty(List<T> l)
{
	if (l.pHead == l.pTail == NULL)
		return true;
	return false;
}
template <class T>
void addTail(List<T> &l, T x)
{
	Node<T>* p = Getnode(x);
	if (l.pHead == NULL && l.pTail == NULL)
	{
		addHead(l, x);
	}
	else
	{
		p->pPrev = l.pTail;
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
template <class T>
Node<T>* find(List<T> l, T x)
{
	Node<T>* p = l.pHead;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}
template <class T>
void deleteHead(List<T> &l)
{
	if (l.pHead == l.pTail)
	{
		delete l.pHead;
		l.pHead = l.pTail = NULL;
	}
	else
	{
		Node<T>* temp = l.pHead;
		l.pHead->pPrev = NULL;
		l.pHead = l.pHead->pNext;
		delete temp;
	}
}
template <class T>
void deleteTail(List<T> &l)
{
	if (l.pHead == l.pTail)
	{
		delete l.pHead;
		l.pHead = l.pTail = NULL;
	}
	else
	{
		Node *temp = l.pHead;
		while (temp->pNext != NULL)
			temp = temp->pNext;
		Node* cur = l.pTail;
		l.pTail = l.pTail->pPrev;
		l.pTail->pNext = NULL;
		delete cur;
	}
}
template <class T>
void RemoveList(List<T> &l)
{
	Node<T>* p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		p->pPrev = NULL;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
#endif