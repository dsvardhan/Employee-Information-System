#include "address.h"

int address::counter = 0;
//Setters
void address::setID(int i) {
	id = i;
};
void address::setZip(int z) {
	zip = z;
};
void address::setStNum(int sn) {
	streetNum = sn;
};

void address::setStName(const char*stn) {
    //We cannot simply assign the char* to anothe char *
   //1) Release any memory that may have been previously allocated
    if (streetName != nullptr)
        delete[] streetName;
    //2) Determine how many characters are needed for the name
    int i = 0;
    while (stn[i++] != '\0');
    //3) Allocate memory for the name
    streetName = new char[i];
    i = 0;
    //4) copy element by element
    while (stn[i] != '\0') {
        streetName[i] = stn[i];
        i++;
    }
    //Do not forget to add the string termination/null character/char 0 at the end of the string
    streetName[i] = '\0';
};


void address::setCity(const char*c) {
    //We cannot simply assign the char* to anothe char *
  //1) Release any memory that may have been previously allocated
    if (city!= nullptr)
        delete[] city;
    //2) Determine how many characters are needed for the name
    int i = 0;
    while (c[i++] != '\0');
    //3) Allocate memory for the name
     city=new char[i];
    i = 0;
    //4) copy element by element
    while (c[i] != '\0') {
        city[i] = c[i];
        i++;
    }
    //Do not forget to add the string termination/null character/char 0 at the end of the string
    city[i] = '\0';
};


void address::setState(const char* s) {
    //We cannot simply assign the char* to anothe char *
  //1) Release any memory that may have been previously allocated
    if (state != nullptr)
        delete[] state;
    //2) Determine how many characters are needed for the name
    int i = 0;
    while (s[i++] != '\0');
    //3) Allocate memory for the name
    state = new char[i];
    i = 0;
    //4) copy element by element
    while (s[i] != '\0') {
        state[i] = s[i];
        i++;
    }
    //Do not forget to add the string termination/null character/char 0 at the end of the string
    state[i] = '\0';
};


//Getters
int address::getID()const {
    return id;
};
int address::getZip()const {
    return zip;
};
int address::getStNum()const {
    return streetNum;
};

char* address::getStName()const {
    return streetName;
};
char* address::getCity() const{
    return city;
};
char* address::getState()const{
    return state;
};

// Empty Constructor
address::address() {
        id = 999999;
        streetNum = 0;
        streetName = nullptr;
        city = nullptr;
        state = nullptr;
        zip = 0;

}


//Parameterized
address::address(int id= 999999, int streetNum=0,   char* sn=nullptr,  char* c=nullptr,  char* s=nullptr, int zip=0) {
    this->id = id;
    this->streetNum = streetNum;
    this->zip = zip;

    //this->streetName = nullptr;
    //this->city = nullptr;
    //this->state= nullptr;


    if ( sn!= nullptr)
        setStName(sn);

    if (c != nullptr)
        setCity(c);

    if (s != nullptr)
        setState(s);

    counter++;
};

//Copy Constructor
address::address(const address& add) {
    id = add.getID();
    streetNum = add.getStNum();
    zip = add.getZip();

    setStName(add.getStName());
    setCity(add.getCity());
    setState(add.getState());

    counter++;
};

//Destructor
address::~address() {
    delete[]streetName;
    delete[]city;
    delete[]state;

    counter--;
};


//Friend Function
void frndDisplayAdd(address& obj) {
    if (obj.id != 0)
        cout << obj.id<< "\t";

    if (obj.streetNum != 0)
        cout << obj.streetNum << "\t";

    if (obj.streetName != nullptr)
        cout << obj.streetName << "\n";

    if (obj.city != nullptr)
        cout << obj.city << "\n";

    if (obj.state != nullptr)
        cout << obj.state << "\t";

    if (obj.zip != 0)
        cout << obj.zip << "\n";
};