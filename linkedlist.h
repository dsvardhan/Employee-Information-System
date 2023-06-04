#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "record.h"
#include<fstream>

struct node {
public:
	record* data;
	node* next;

	//Empty Constructor
	node() {
		data = nullptr;
		next = nullptr;
	};

	//copyconstructor
	node( const node*&obj){
		data = obj->data;
		next = obj->next;

	}

	//Destructor
	~node() {
		delete data;
		delete next;
	};
};

class linkedList{
public:

	node* head=nullptr;
	node* sorted;

	bool isEmpty();

	int getSize();

	void push(node*);

	void deleteNode();

	//Add a node at the end of the list
	void append(node* newNode);

	void removeLast();

	//Index value is the position relative to the head node.
	// Head node has index 0, and tail node will have index n-1... just like in arrays
	void removebyIndex(int n);

	//Insert by index
	void insertByIndex(int n, node* newNode);

	//Show function
	void showNode(node* head);

	//Search Address
	node*searchAddByID(int);

	void searchAddByZip(int);

	void searchAddByCity(const char*);


	//Read address
	bool readAddress(const char* fn);

	//Read employee
	bool readEmployee(const char* fn);

	//Constructor
	linkedList();

	//Helper destructor
	void clearList();

	//Destructor
	~linkedList();

	void sortedInsertID(node*);

	void sortedInsertDiv(node*);

	void sortedInsertZip(node*);

	node* insertionSortID();

	node* insertionSortDiv();

	node* insertionSortZip();

	void showsearchAddByID(int id);

};

#endif

