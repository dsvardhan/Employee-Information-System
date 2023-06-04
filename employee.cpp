#include "employee.h"

int employee::counter=0;
//Setters
void employee::setID(int i) {
	id = i;
};
void  employee::setName(const char* n) {
	//We cannot simply assign the char* to anothe char *
  //1) Release any memory that may have been previously allocated
	if (fullname != nullptr)
		delete[] fullname;
	//2) Determine how many characters are needed for the name
	int i = 0;
	while (n[i++] != '\0');
	//3) Allocate memory for the name
	fullname = new char[i];
	i = 0;
	//4) copy element by element
	while (n[i] != '\0') {
		fullname[i] = n[i];
		i++;
	}
	//Do not forget to add the string termination/null character/char 0 at the end of the string
	fullname[i] = '\0';
};

void employee::setDiv(int d) {
	div = (DEPARTMENT)d;
}

void employee::setDiv(DEPARTMENT d) {
	div = d;
};


//Getters
int employee::getID() const{
	return id;
};
char* employee::getName()const {
	return fullname;
};

DEPARTMENT employee::getDiv() const{
	return div;
}
// Empty Constructor
employee::employee(){
	id = 999999;
	fullname = nullptr;
	div = DEFAULT;
};

//Parameterized
employee::employee(int id= 999999,  char* name=nullptr, DEPARTMENT d=DEFAULT) {
	this->id = id;
	setName(name);
	setDiv(d);
	counter++;
};

//Copy Constructor
employee::employee(const employee&obj) {

	id = obj.getID();
	setName(obj.getName());
	setDiv(obj.getDiv());
	counter++;
};

//Destructor
employee::~employee() {
	if(fullname!=nullptr)
	delete[]fullname;
	counter--;
};


//Friend Function
void frndDisplayEmploy(employee&obj) {
	if (obj.fullname != nullptr) {
		cout << obj.fullname << "\t";
	}
	if (obj.id != 0) {
		cout << obj.id << "\t";
	}
	if (obj.div != DEFAULT) {

		int opt = obj.div;

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
	}
};
