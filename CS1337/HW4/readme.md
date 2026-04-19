<!-- To preview this markdown file in VSCode: Ctrl+Shift+V -->

# CS1 Portfolio - Bushra Rahman
## CS 1337/HW4: Classes, Inheritance, and Polymorphism

This is the repository for [CS 1337/HW4](/CS1337/HW4).

## Execution Instructions
Open terminal while in `CS1_Portfolio` and run:
<!-- CODE START -->
```
cd CS1337/HW4/src
g++ Aircraft-Test.cpp Aircraft.cpp AcrobatAircraft.cpp FreightAircraft.cpp PassengerAircraft.cpp
.\a.exe
```
<!-- CODE END -->
This compilation instruction produces an executable directly in the `src` folder.

Alternative compilation instructions can be followed, if desired, to produce the executable elsewhere (eg. in a `build` folder).

## Homework Instructions
* [HW 4: Classes, Inheritance, and Polymorphism](/CS1337/HW4/HW4_Classes.pdf)

## src Folder
### Source Files
* [Aircraft-Test.cpp](/CS1337/HW4/src/Aircraft-Test.cpp): program driver containing `main()` and 8 helper functions
* [Aircraft.cpp](/CS1337/HW4/src/Aircraft.cpp): defines 10 of 11 functions for the base class
* [AcrobatAircraft.cpp](/CS1337/HW4/src/AcrobatAircraft.cpp): defines 8 functions for a subclass
* [FreightAircraft.cpp](/CS1337/HW4/src/FreightAircraft.cpp): defines 7 functions for a subclass
* [PassengerAircraft.cpp](/CS1337/HW4/src/PassengerAircraft.cpp): defines 6 functions for a subclass

### Header Files
* [Aircraft.h](/CS1337/HW4/src/Aircraft.h): contains the class definition of the base class, including 1 inline function
* [AcrobatAircraft.h](/CS1337/HW4/src/AcrobatAircraft.h): contains the class definition of a subclass
* [FreightAircraft.h](/CS1337/HW4/src/FreightAircraft.h): contains the class definition of a subclass
* [PassengerAircraft.h](/CS1337/HW4/src/PassengerAircraft.h): contains the class definition of a subclass

## Input Files
Input files need to be provided using their relative path (ie. with the prefix `../`).
* [aircraft.txt](/CS1337/HW4/aircraft.txt): input file choice 1 (for standard output)
* [test.txt](/CS1337/HW4/test.txt): input file choice 2 (for program testing)
