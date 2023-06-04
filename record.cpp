#include "record.h"

// Empty Constructor
//record::record():address(),employee() {};

//Parameterized
record::record(int id= 999999, int stNum=0, char* streetName=nullptr ,  char* city=nullptr , char* state=nullptr, int zip=0, char* name=nullptr, DEPARTMENT div=DEFAULT) :address(id, stNum, streetName, city, state, zip), employee(id, name, div) {};

record::record(int id, int stNum,  char* streetName,  char* city,  char* state, int zip):address(id,stNum,streetName,city,state,zip),employee(){};

record::record(int id,  char* name, DEPARTMENT div) :address(), employee(id,name,div) {

};
//Copy Constructor
record::record(const record& obj):address(obj),employee(obj){};


void record::show() {

	cout << left;
	if (address::getID() != 999999)
		cout << setw(4) << address::getID();//<< "\t";
	else {
		cout << setw(4) << employee::getID();// << "\t";
	}
	if (getName() != nullptr) {
		cout <<setw(20) << getName();
	}
	else {
		cout << setw(20)<<"None";
	}
	cout << setw(6) << getStNum();// << "\t";
	if (getStName() != nullptr) {
		cout << setw(20)<<getStName();
	}
	else {
		cout << setw(20)<< "None";
	}

	if (getCity() != nullptr) {
		cout << setw(20)<<getCity();
	}
	else {
		cout << setw(20)<<"None";
	}
	if (getState() != nullptr) {
		cout << setw(5)<<getState();
	}
	else {
		cout << setw(5)<<"None";
	}
	cout << "\t" << setw(7)<<getZip()<<setw(15);

	int opt = getDiv();

	switch (opt) {
	case SALES:cout << "SALES";
		break;
	case CUSTOMER_SERVICE:cout << "CUSTOMER SERVICE";
		break;
	case PRODUCTION:cout << "PRODUCTION";
		break;
	case HUMAN_RESOURCES:cout << "HUMAN RESOURCES";
		break;
	case ACCOUNTING:cout << "ACCOUNTING";
		break;
	case RESEARCH_AND_DEVELOPMENT: cout << "RESEARCH AND DEVELOPMENT";
		break;
	}
	cout << "\n";
}
//Destructor
//record::~record() {};
