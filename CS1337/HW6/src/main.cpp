/*	Author:			Bushra Rahman
	Course:			CS 1337 (Fall 2019)
	Date:			12/5/2019
	main.cpp:		This source file is the driver of the program. 
					It demonstrates the implementation of the observer design pattern in the Subject and various Observer classes. */

// include all the header files for all the classes
#include "Subject.h"
#include "BankObserver.h"
#include "SchoolObserver.h"
#include "CreditObserver.h"

#include <iostream>
using namespace std;



int main()
{
	// initialize a Subject object with an initial address
	Subject subject("123 Gensokyo St");

	// create objects of 3 different Observer classes
	BankObserver bankObserver;
	SchoolObserver schoolObserver;
	CreditObserver creditObserver;

	// add those Observers to the Subject object
	subject.addObserver(bankObserver);
	subject.addObserver(schoolObserver);
	subject.addObserver(creditObserver);

	// more Observer objects of the schoolObserver class are registered with the Subject object
	SchoolObserver schoolObserver2;
	subject.addObserver(schoolObserver2);
	SchoolObserver schoolObserver3;
	subject.addObserver(schoolObserver3);
	SchoolObserver schoolObserver4;
	subject.addObserver(schoolObserver4);


	// change the Subject object's address
	subject.setAddress("567 Koumakan Dr");

	// unregister the first schoolObserver object from the Subject object
	// calling removeObserver on the same Observer object more than once will output an error message
	cout << endl;
	subject.removeObserver(schoolObserver);
	subject.removeObserver(schoolObserver);

	// more Observer objects of the bankObserver class are registered with the Subject object
	BankObserver bankObserver2;
	subject.addObserver(bankObserver2);
	BankObserver bankObserver3;
	subject.addObserver(bankObserver3);
	BankObserver bankObserver4;
	subject.addObserver(bankObserver4);

	// change the Subject object's address again
	subject.setAddress("789 Hakugyokurou Blvd");

	// unregister the creditObserver object from the Subject object and change the Subject object's address again
	cout << endl;
	subject.removeObserver(creditObserver);
	subject.setAddress("345 Eientei Rd");

	// unregister the first bankObserver object from the Subject object and change the Subject object's address again
	cout << endl;
	subject.removeObserver(bankObserver);
	subject.setAddress("1000 Chireiden Pkwy");

	// calling removeObserver on the same Observer object more than once will output an error message
	subject.removeObserver(bankObserver);

	return 0;
}