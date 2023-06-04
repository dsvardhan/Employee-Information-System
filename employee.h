#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
using namespace std;

enum DEPARTMENT{DEFAULT,SALES,CUSTOMER_SERVICE,PRODUCTION,HUMAN_RESOURCES,ACCOUNTING,RESEARCH_AND_DEVELOPMENT};


class employee
{
private:
	int id;
	char* fullname;
	DEPARTMENT div;
	static int counter;
public:


	//Setters
	void setID(int);
	void setName(const char*);
	void setDiv(int);
	void setDiv(DEPARTMENT);


	//Getters
	int getID()const;
	char* getName()const;
	DEPARTMENT getDiv()const;

	// Empty Constructor
	employee();

	//Parameterized
	employee(int, char*,DEPARTMENT);

	//Copy Constructor
	employee(const employee&);

	//Destructor
	~employee();

	
	//Friend Function
	friend void frndDisplayEmploy(employee&);



};

#endif

