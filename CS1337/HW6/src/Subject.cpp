/*	Author:			            Bushra Rahman
	Course:			            CS 1337 (Fall 2019)
	Date:			            12/5/2019
	Subject.cpp:	    		This source file contains the definitions for the 6 methods defined in the Subject class. */

#include "Subject.h"			// header file for this class
#include "AbstractObserver.h"	// header file for the AbstractObserver abstract class
#include <list>
#include <iostream>
using namespace std;

/*	Function Type:		constructor
	Descr:				This function initializes the string field in the Subject object.
	Input:    			string addr
						The string for a person's physical address.
	Return:				None, initializes a Subject object. */
Subject::Subject(string addr)
{
	address = addr;

}



/*	Function Name:		addObserver()
	Descr:				This function adds Observer objects to the list.
	Input:    			AbstractObserver &observer
						Reference to an AbstractObserver that will be directly modified by this function.
	Return:				None. */
void Subject::addObserver(AbstractObserver &observer)
{
	observers.push_back(&observer);
}



/*	Function Name:		removeObserver()
	Descr:				This function removes Observer objects from the list.
	Input:    			AbstractObserver &observer
						Reference to an AbstractObserver that will be directly modified by this function.
	Return:				None. */
void Subject::removeObserver(AbstractObserver &observer)
{
	// define an iterator for the list
	list<AbstractObserver *>::iterator iter;

	// flag
	bool found = false;

	// pointer to the current Observer pointed at by iter in the for loop below
	AbstractObserver *ptrOtherObserver;

	// loop through the list of Observers
	for (iter = observers.begin(); iter != observers.end(); iter++)
	{
		// recast ptrOtherObserver
		ptrOtherObserver = reinterpret_cast<AbstractObserver *>(*iter);

		// if the Observer in the function argument is the Observer pointed at by ptrOtherObserver
		if(observer == *ptrOtherObserver)   // usage of the overloaded == operator for Observer objects
		{
			// remove that Observer from the list
			observers.erase(iter);
			// set flag to true
			found = true;
			// break out of the loop because the argument has been found
			break;
		}
	}
	// if the flag was never set to true
	if(!found)
	{
		cout << "removeObserver(): no match found for object ID " << observer.getObserverID() << endl;
	}
}



/*	Function Name:		getAddress()
	Descr:				This function is the getter for address.
	Input:    			None.
	Return:				string address
						The person's directly-retrieved physical address. */
string Subject::getAddress()
{
	return address;
}



/*	Function Name:		setAddress()
	Descr:				This function is the setter for address.
	Input:    			string newAddress
						The inputted string to be set as address.
	Return:				None. */
void Subject::setAddress(string newAddress)
{
	address = newAddress;
	notify();	// notify() is called whenever the Subject's address is changed.
	// notify() allows the Observers to see that the Subject's address has changed.
}



/*	Function Name:		notify()
	Descr:				This function is called in setAddress().
						Once the new address is set, it is used in notify() as the argument of subjectChanged(),
						which is called on every Observer in the list.
						Thus, every Observer is notified when the subject's address changes.
						In summary: setAddress() calls notify() and notify() calls subjectChanged().
	Input:    			None.
	Return:				None. */
void Subject::notify()
{
	// define an iterator for the list
	list<AbstractObserver *>::iterator iter;

	// pointer to the current Observer pointed at by iter in the for loop below
	AbstractObserver *ptrOtherObserver;

	// loop through the list of Observers
	for (iter = observers.begin(); iter != observers.end(); iter++)
	{
		// recast ptrOtherObserver
		ptrOtherObserver = reinterpret_cast<AbstractObserver *>(*iter);

		// calls the AbstractObserver method subjectChanged() with the
		// address of the Subject as the argument
		ptrOtherObserver->subjectChanged(address);
	}
}