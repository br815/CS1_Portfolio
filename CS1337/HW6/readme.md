<!-- To preview this markdown file in VSCode: Ctrl+Shift+V -->

# CS1 Portfolio - Bushra Rahman
## CS 1337/HW6: Design Patterns Continued

This is the repository for [CS 1337/HW6](/CS1337/HW6).

## Execution Instructions
Open terminal while in `CS1_Portfolio` and run:
<!-- CODE START -->
```
cd CS1337/HW6/src
g++ main.cpp AbstractObserver.cpp Subject.cpp
.\a.exe
```
<!-- CODE END -->
This compilation instruction produces an executable directly in the `src` folder.

Alternative compilation instructions can be followed, if desired, to produce the executable elsewhere (eg. in a `build` folder).

## Homework Instructions
* [HW 6: Design Patterns Continued](/CS1337/HW6/HW6_DesignPatternsCont.pdf)

## src Folder
### Source Files
* [main.cpp](/CS1337/HW6/src/main.cpp): program driver containing `main()`
* [AbstractObserver.cpp](/CS1337/HW6/src/AbstractObserver.cpp): defines 1 static member variable for the abstract base class
* [Subject.cpp](/CS1337/HW6/src/Subject.cpp): defines 6 functions for a class

### Header Files
* [AbstractObserver.h](/CS1337/HW6/src/AbstractObserver.h): contains the class definition of the abstract base class, including 3 inline functions, 1 overloaded function, and 1 pure virtual function defined in subclasses
* [BankObserver.h](/CS1337/HW6/src/BankObserver.h): contains the class definition of a subclass, including 2 inline functions
* [CreditObserver.h](/CS1337/HW6/src/CreditObserver.h): contains the class definition of a subclass, including 2 inline functions
* [SchoolObserver.h](/CS1337/HW6/src/SchoolObserver.h): contains the class definition of a subclass, including 2 inline functions
* [Subject.h](/CS1337/HW6/src/Subject.h): contains the class definition of a class
