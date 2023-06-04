#ifndef RECORD_H
#define RECORD_H

#include"address.h"
#include"employee.h"
#include<iomanip>;


class record:public address,public employee{
public:

	// Empty Constructor
	//record();

	//Parameterized
	record(int id , int stNum,  char *,  char*,  char*, int,  char*, DEPARTMENT);
	record(int, int, char*, char*,  char*, int);
	record(int,  char*, DEPARTMENT);


	void show();
	//record(int = 0,int=0,char*, )

	//Copy Constructor
	record(const record&);

	//Destructor
	//~record();
};
#endif

//class record:public temperature,weekday{
// public:
// void display(){
//	cout<<"ID"<<weekday::
// }
//}
