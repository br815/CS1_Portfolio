<!-- To preview this markdown file in VSCode: Ctrl+Shift+V -->

# CS1 Portfolio | HW4: Classes, Inheritance, and Polymorphism
## Author: Bushra Rahman
This is the repository for [CS 1337/HW4](/CS1337/HW4).

## Execution Instructions
Open terminal in `CS1_Portfolio` and run:
<!-- CODE START -->
```
cd CS1337/HW4
mkdir build
g++ src/Aircraft-Test.cpp src/Aircraft.cpp src/AcrobatAircraft.cpp src/FreightAircraft.cpp src/PassengerAircraft.cpp -o build/HW4
build/HW4
```
<!-- CODE END -->

For a project like this with more than one or two source files, the wildcard `*.cpp` can be used instead to compile:
<!-- CODE START -->
```
g++ src/*.cpp -o build/HW4
```
<!-- CODE END -->

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
* [aircraft.txt](/CS1337/HW4/aircraft.txt): input file choice 1 (for standard output)
* [test.txt](/CS1337/HW4/test.txt): input file choice 2 (for program testing)
