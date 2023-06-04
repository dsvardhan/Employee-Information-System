#include<iostream>
#include<fstream>
#include "linkedlist.h"
bool a = false, b = false;
char fnA[100], fnE[100];


void menu(linkedList* d) {

	char choice, sub;


	cout << "a.Enter address file location\nb.Enter employee file location\nc.Read files\nd.Display Data\n";
	cout << "e.Search:\n\ti. ID\n\tii.ZipCode\n\tiii.City\n";
	cout << "f.Sort:\n\ti. ID\n\tii.ZipCode\n\tiii.Department\n";
	cout << "g. Display\n";
	cout << "h.Exit\n";

	cin >> choice;

	switch (choice) {
	case 'a': {
		cout << "Enter location\n";
		cin >> fnA;

		a = true;
		menu(d);
	}
			break;
	case 'b': {
		cout << "Enter location\n";
		cin >> fnE;

		b = true;
		menu(d);
	}
			break;
	case 'c': {

		if (a && b) {
			d->readAddress(fnA);
			d->readEmployee(fnE);
			menu(d);
		}
		else {
			cout << "Please enter file names\n";
			menu(d);
		}
	}
			break;
	case 'd': {

		//d->deleteNode();

		d->showNode(d->head);
		menu(d);
	}
			break;
	case 'e': {

		int i;

		cout << "Enter choice\t";
		cin >> i;

		switch (i) {
		case 1: {
			int j;

			cout << "enter id\t";
			cin >> j;

			d->showsearchAddByID(j);
			menu(d);
		}
			  break;
		case 2: {
			int j;

			cout << "enter zip\t";
			cin >> j;

			d->searchAddByZip(j);

			menu(d);
		}
			  break;
		case 3: {
			char helper[100];

			ifstream in;

			cout << "enter city\t";
			cin>>helper;

			d->searchAddByCity(helper);
			menu(d);
		}
			  break;


		}
	}
			break;
	case 'f': {
		int i;

		cout << "Enter choice\t";
		cin >> i;

		switch (i) {
		case 1: {


			node* n = d->insertionSortID();


			d->showNode(n);

			menu(d);
		}
			  break;
		case 2: {

			node* n = d->insertionSortZip();


			d->showNode(n);

			menu(d);
		}
			  break;
		case 3: {
			char helper[100];



			node* n = d->insertionSortDiv();


			d->showNode(n);
			menu(d);
		}
			  break;
		}

	}
			break;
	case 'g': {

	}
			break;
	case 'h': {
		return;
	}
			break;
	};
}

	void displayAdd(address & obj){

	}

	void displayEmploy(employee & obj) {
		if (obj.getName() != nullptr) {
			cout << obj.getName() << "\t";
		}
		if (obj.getID() != 0) {
			cout << obj.getID() << "\t";
		}
		if (obj.getDiv() != DEFAULT) {

			int opt = obj.getDiv();
			switch (opt) {
			case 1:cout << "SALES";
				break;
			case 2:cout << "CUSTOMER SERVICE";
				break;
			case 3:cout << "PRODUCTION";
				break;
			case 4:cout << "HUMAN RESOURCES";
				break;
			case 5:cout << "ACCOUNTING";
				break;
			case 6: cout << "RESEARCH AND DEVELOPMENT";
				break;
			}

		}
	}


	

int main() {

	linkedList* d=new linkedList();
	menu(d);
	return 0;
}