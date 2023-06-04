#ifndef ADDRESS_H
#define ADDRESS_H

#include<iostream>
using namespace std;

class address
{
private:
	int id, zip, streetNum;
	char* streetName; 
	char* city;
	char* state;
	
	static int counter;

	//Friend Function
	friend void frndDisplayAdd(address&);
public:

	
	//Setters
	void setID(int);
	void setZip(int);
	void setStNum(int);

	void setStName(const char*);
	void setCity(const char*);
	void setState(const char*);


	//Getters
	int getID()const;
	int getZip()const;
	int getStNum()const;

	char* getStName()const;
	char* getCity()const;
	char* getState()const;

	// Empty Constructor
	address();

	//Parameterized
	address(int, int, char*,  char*,  char*, int);

	//Copy Constructor
	address(const address&);

	//Destructor
	~address();

	



};
#endif

