#include "linkedlist.h"

int getLength(const char* str) {
	int i = 0;
	while (str[i++] != '\0');
	return i-1; //Notice the -1 using this implementation
}

void copyString(const char* src, char*& dst) {

	if (dst != nullptr)
		delete[] dst;

	int strlen = getLength(src) + 1;

	dst = new char[strlen];

	int i = 0;
	while (src[i] != '\0') {
		dst[i] = src[i];

		i++;
	}
	dst[i] = '\0';
}

bool strcomp(const char* strA, const char* strB) {
	int counter = 0;
	//Check here the size of both
	while (strA[counter] != '\0') {
		if (strA[counter] != strB[counter])
			return false;
		counter++;
	}
	if (strB[counter] == '\0')
		return true;
	else return false;
	
}

void linkedList::push(node* n)
{
	//node* new_node = new node();
	//new_node->data = new_data;
	n->next = head;
	head = n;
}

void linkedList::deleteNode()
{

	node* temp = head;
	node* prev = NULL;

	
	if (temp != NULL && temp->data->getName() == nullptr)
	{
		head = temp->next; 
		delete temp;            
		return;
	}
	else
	{
		while (temp != NULL && temp->data->getName() != nullptr)
		{
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL)
			return;


		prev->next = temp->next;

		
		delete temp;
	}
}


//bool linkedList::isEmpty() {
//
//};

//int linkedList::getSize() {
//
//};

//Add a node at the end of the list
void linkedList::append(node* newNode) {
	if (head != nullptr)
	{
		//Start iterating from the head node
		node* iter = head;

		//Notice that we are looking for the last node in the list
		//The property next form last node in the list, will be pointing to null
		while (iter->next != nullptr) {
			iter = iter->next;
		}
		iter->next = newNode;
	}//If there are no nodes in the list, then the new node becomes the head node
	else
		head = newNode;
};

void linkedList::removeLast() {
	if (head != nullptr) {
		//start iterating from the head node
		node* iter = head;
		//Need to keep track of the prev node
		node* prev = head;
		while (iter->next != nullptr) {
			prev = iter;
			iter = iter->next;
		}
		//Since we are removing the last node, the property next of the node previousto-last should be set to nullptr
		prev->next = nullptr;
		//Now we can delete the last node
		delete iter;
	}
};

//Index value is the position relative to the head node.
// Head node has index 0, and tail node will have index n-1... just like in arrays
void linkedList::removebyIndex(int n) {
	if (head != nullptr) {
		node* iter = head;
		node* prev = head;
		int count = 0;
		while (count < n && iter != nullptr) {
			count++;
			prev = iter;
			iter = iter->next;
		}
		if (iter != nullptr) {
			prev->next = iter->next;
			delete iter;
		}
	}
};

//Insert by index
void linkedList::insertByIndex(int n, node* newNode) {
	if (head != nullptr) {
		node* iter = head;
		node* prev = head;
		int count = 0;
		while (count < n && iter != nullptr) {
			count++;
			prev = iter;
			iter = iter->next;
		}
		if (prev != nullptr) {
			prev->next = newNode;
			newNode->next = iter;
		}
	}
};

//Show function
void linkedList::showNode(node* head) {

	if (head!=nullptr){
		node* iter = head;

		while (iter != nullptr) {
			cout<<left<<fixed;
			if(iter->data->address::getID()!=999999)
			cout << setw(4)<<iter->data->address::getID();
			else {
				cout << setw(4)<< iter->data->employee::getID();
			}
			if (iter->data->getName() != nullptr) {
				cout << setw(20)<< iter->data->getName();
			} 
			else {
				cout << setw(20)<< "None";
			}
			cout << setw(6)<<iter->data->getStNum();
				if (iter->data->getStName() != nullptr) {
					cout << setw(20) << iter->data->getStName();
				}
				else {
					cout << setw(20) <<"None";
				}  
				
				if (iter->data->getCity() != nullptr) {
					cout  << setw(22)<< iter->data->getCity();
				}
				else {
					cout << setw(22)<<"None";
				}
				
				if (iter->data->getState() != nullptr) {
					cout << setw(5)<<iter->data->getState();
				}
				else {
					cout << setw(5)<<"None";
				} 
				cout << setw(7) << iter->data->getZip()<< setw(20);

				int opt = iter->data->getDiv();
					
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
				default:cout << "None";
					break;
				}
				cout<< "\n";

			iter = iter->next;
		}
	}
};

//Search Address
node* linkedList::searchAddByID(int id) {

	node* searchId = new node();

	//linkedList* d1=new linkedList();
	//d1->head = nullptr;

	if (head != nullptr) {
		node* l = head;

		while (l!= nullptr) {
			if (l->data->address::getID() == id) {
				
				//searchId->data = l->data;
				//searchId->next = nullptr;
				//d1->append(searchId);

				
				//iter = iter->next;

				return l;//
			}
			else{
				//return nullptr;
			}
			//delete searchId;
			
			l = l->next;
		}
	}

	//return searchId;
	//return d1->head;

	
};

void linkedList::showsearchAddByID(int id) {

	node* searchId = new node();

	//linkedList* d1=new linkedList();
	//d1->head = nullptr;

	if (head != nullptr) {
		node* l = head;

		while (l != nullptr) {
			if (l->data->address::getID() == id) {

				//searchId->data = l->data;
				//searchId->next = nullptr;
				//d1->append(searchId);


				//iter = iter->next;

				//return l;

				l->data->show();
			}
			else {
				//return nullptr;
			}
			//delete searchId;

			l = l->next;
		}
	}

	//return searchId;
	//return d1->head;


};

void  linkedList::searchAddByZip(int z) {
	node* searchId = new node();

	//linkedList* d1=new linkedList();
	//d1->head = nullptr;

	if (head != nullptr) {
		node* l = head;

		while (l != nullptr) {
			if (l->data->address::getZip() == z) {

				//searchId->data = l->data;
				//searchId->next = nullptr;
				//d1->append(searchId);


				//iter = iter->next;

				//return l;

				l->data->show();
			}
			else {
				//return nullptr;
			}
			//delete searchId;

			l = l->next;
		}
	}
};

void linkedList::searchAddByCity(const char* city) {

	node* searchId = new node();

	//linkedList* d1=new linkedList();
	//d1->head = nullptr;

	if (head != nullptr) {
		node* l = head;

		while (l != nullptr) {

			if (l->data->getCity() != nullptr) {
				bool comp = strcomp(l->data->getCity(), city);

				if (comp) {

					//searchId->data = l->data;
					//searchId->next = nullptr;
					//d1->append(searchId);


					//iter = iter->next;

					//return l;

					l->data->show();
				}
			}

			l = l->next;
		}
	}

	//return d->head;
};

//Sort
//node* linkedList::sortAddByID(int) {
//
//};
//
//node* linkedList::sortAddByZip(int) {
//
//};
//
//node* linkedList::sortAddByDiv(DEPARTMENT) {
//
//};


//Read address
bool linkedList::readAddress(const char* fn) {
	ifstream in;
	in.open(fn);

	if (!in.is_open()) {
		return false;
	}
	int id, stNum, z;
	char helperstn[100];
	char helperc[100];
	char helpers[100];
	char* streetName;
	char* c;
	char* s;
	char* name;
	DEPARTMENT dep;

	while (!in.eof()) {
		in >> id >> stNum;
		in.getline(helperstn, 100);
		//copyString(helperstn, streetName);

		in.getline(helperc, 100);
		//copyString(helperc, c);

		in >> helpers;
		//copyString(helpers, s);

		
		in >> z;

		//address* r = new address(id, stNum, helperstn, helperc, helpers, z);

		record* r = new record(id, stNum, helperstn, helperc, helpers, z);
		node* n = new node();
		n->data = r;
		//n->data = (record*)r;
		n->next = nullptr;

		if(n!=nullptr)
		append(n);

	}
	//showNode(head);

	in.close();

	return true;
};

bool linkedList::readEmployee(const char* fn) {

	//showNode(head);
	int id, stNum, h, zip;
	char* stName;
	char* city;
	char* state;
	DEPARTMENT dep;
	char helper[100];

	ifstream in;
	in.open(fn);

	record* r;
	node* n;

	linkedList* d2 = new linkedList;

	if (!in.is_open()) {
		return false;
	}

	node* noAid = new node();
	//node* i = head;
	node* j = d2->head;

	while (!in.eof()) {
		in >> id;
		in.getline(helper, 100);
		in >> h;

		dep = (DEPARTMENT) h;

	


		 n=searchAddByID(id);


		 if (n == nullptr) {
			 r = new record(id, helper, dep);

			 node* p = new node();
			 p->data = r;

			 append(p);
		 }
		 else {
			 if (n->data->getName() == nullptr) {
				 n->data->setName(helper);
				 n->data->setDiv(dep);
			 }
			 else {
				 node* k = new node();
				 record* ar = new record(*n->data);
				 k->data = ar;
				 k->next = nullptr;

				 k->data->employee::setID(id);
				 k->data->setName(helper);
				 k->data->setDiv(dep);

				 append(k);
			 }
		 }

		 

		
			
		//if (noAid != nullptr) {
		//	d2->append(noAid);
		//	delete noAid;
		//}

		//showNode(head);
	}
	//showNode(head);

	//d2->showNode(d2->head);

	//d2->showNode(d2->head);
	//append(d2->head);
	
}

void linkedList::sortedInsertID(node* newNode)
{
	

	/* Special case for the head end */
	if (sorted == NULL || sorted->data->address::getID() >= newNode->data->address::getID() ){
		newNode->next = sorted;
		sorted = newNode;
	}
	else {
		node* current = sorted;
		/* Locate the node before the point of insertion
		 */
		while (current->next != NULL
			&& current->next->data->address::getID() < newNode->data->address::getID()) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void linkedList::sortedInsertDiv(node* newNode)
{

	/* Special case for the head end */
	if (sorted == NULL || sorted->data->getDiv() >= newNode->data->getDiv()) {
		newNode->next = sorted;
		sorted = newNode;
	}
	else {
		node* current = sorted;
		/* Locate the node before the point of insertion
		 */
		while (current->next != NULL
			&& current->next->data->getDiv() < newNode->data->getDiv()) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

void linkedList::sortedInsertZip(node* newNode)
{
	

	/* Special case for the head end */
	if (sorted == NULL || sorted->data->getZip() >= newNode->data->getZip()) {
		newNode->next = sorted;
		sorted = newNode;
	}
	else {
		node* current = sorted;
		/* Locate the node before the point of insertion
		 */
		while (current->next != NULL
			&& current->next->data->getZip() < newNode->data->getZip()) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

node* linkedList::insertionSortID()
{
	// Initialize sorted linked list
	sorted = NULL;
	node* current = head;
	// Traverse the given linked list and insert every
	// node to sorted
	while (current != NULL) {
		// Store next for next iteration
		node* next = current->next;
		// insert current in sorted linked list
		sortedInsertID(current);
		// Update current
		current = next;
	}
	// Update head_ref to point to sorted linked list
	node* newhead = sorted;

	return newhead;
}

node* linkedList::insertionSortDiv()
{
	// Initialize sorted linked list
	sorted = NULL;
	node* current = head;
	// Traverse the given linked list and insert every
	// node to sorted
	while (current != NULL) {
		// Store next for next iteration
		node* next = current->next;
		// insert current in sorted linked list
		sortedInsertDiv(current);
		// Update current
		current = next;
	}
	// Update head_ref to point to sorted linked list
	node* newhead = sorted;

	return newhead;
}

node* linkedList::insertionSortZip()
{
	// Initialize sorted linked list
	 sorted = NULL;
	node* current = head;
	// Traverse the given linked list and insert every
	// node to sorted
	while (current != NULL) {
		// Store next for next iteration
		node* next = current->next;
		// insert current in sorted linked list
		sortedInsertZip(current);
		// Update current
		current = next;
	}
	// Update head_ref to point to sorted linked list
	node* newhead = sorted;

	return newhead;
}

//Helper function to linkedlist destructor
void linkedList::clearList() {
	node* iter = head;
	node* cpy = head;
	while (iter != nullptr) {
		cpy = iter->next;
		delete iter;
		iter = cpy;
	}
}

linkedList::linkedList() {
	head = nullptr;
}

linkedList::~linkedList() {
	clearList();
}