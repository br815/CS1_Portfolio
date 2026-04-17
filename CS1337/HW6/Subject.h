/*	Author:			            Bushra Rahman
	Course:			            CS 1337 (Fall 2019)
	Date:			            12/5/2019
	Subject.h:	                This header file contains the class definition for Subject. */

// header for #include guard (preprocessor directives)
#ifndef SUBJECT_H_              // if SUBJECT_H_ is not defined, define it (start of header guard)
#define SUBJECT_H_              // define SUBJECT_H_ once to prevent multiple inclusions
#include "AbstractObserver.h"   // include header file for AbstractObserver
#include <string>
#include <list>
using namespace std;

class Subject
{
private:
    string address;                         // person's physical address
    list<AbstractObserver *> observers;     // STL list of registered Observers
    void notify();                          // notifies Observers of changes to address
public:
    // constructor
    Subject(string addr);

    // adds Observers to the list
    void addObserver(AbstractObserver& observer);

    // removes Observers from the list
    void removeObserver(AbstractObserver& observer);

    // getter for address
    string getAddress();

    // setter for address
    void setAddress(string newAddress);
};

#endif                          // end of "if not defined" ifndef block