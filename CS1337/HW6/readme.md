<!-- To preview this markdown file in VSCode: Ctrl+Shift+V -->

# CS1 Portfolio - Bushra Rahman
## CS 1337/HW6: Design Patterns Continued

This is the repository for [CS 1337/HW6](/CS1337/HW6).

## Execution Instructions
Open terminal and run:
<!-- CODE START -->
```
cd CS1337/HW6
g++ main.cpp AbstractObserver.cpp Subject.cpp
.\a.exe
```
<!-- CODE END -->

## Homework Instructions
* [HW 6: Design Patterns Continued](/CS1337/HW6/HW6_DesignPatternsCont.pdf)

## Source Files
* [main.cpp](/CS1337/HW6/main.cpp): program driver containing main()
* [AbstractObserver.cpp](/CS1337/HW6/AbstractObserver.cpp): defines 1 static member variable for the abstract base class
* [Subject.cpp](/CS1337/HW6/Subject.cpp): defines 6 functions for a class

## Header Files
* [AbstractObserver.h](/CS1337/HW6/AbstractObserver.h): contains the class definition of the abstract base class, including 3 inline functions, 1 overloaded function, and 1 pure virtual function defined in subclasses
* [BankObserver.h](/CS1337/HW6/BankObserver.h): contains the class definition of a subclass, including 2 inline functions
* [CreditObserver.h](/CS1337/HW6/CreditObserver.h): contains the class definition of a subclass, including 2 inline functions
* [SchoolObserver.h](/CS1337/HW6/SchoolObserver.h): contains the class definition of a subclass, including 2 inline functions
* [Subject.h](/CS1337/HW6/Subject.h): contains the class definition of a class
