<!-- To preview this markdown file in VSCode: Ctrl+Shift+V -->

# CS1 Portfolio | HW5: Design Patterns
## Author: Bushra Rahman
This is the repository for [CS 1337/HW5](/CS1337/HW5).

## Execution Instructions
Open terminal in `CS1_Portfolio` and run:
<!-- CODE START -->
```
cd CS1337/HW5
mkdir build
g++ src/LogSingleton-Test.cpp src/CS1337Logger.cpp src/FileLogger.cpp src/ScreenLogger.cpp src/LogSingleton.cpp -o build/HW5
build/HW5
```
<!-- CODE END -->
For a project like this with more than one or two source files, the wildcard `*.cpp` can be used instead to compile:
<!-- CODE START -->
```
g++ src/*.cpp -o build/HW5
```
<!-- CODE END -->

## Homework Instructions
* [HW 5: Design Patterns](/CS1337/HW5/HW5_DesignPatterns.pdf)

## src Folder
### Source Files
* [LogSingleton-Test.cpp](/CS1337/HW5/src/LogSingleton-Test.cpp): program driver containing `main()` and 4 helper functions
* [CS1337Logger.cpp](/CS1337/HW5/src/CS1337Logger.cpp): defines 4 of 6 functions for the abstract base class
* [FileLogger.cpp](/CS1337/HW5/src/FileLogger.cpp): defines 4 functions for a subclass
* [ScreenLogger.cpp](/CS1337/HW5/src/ScreenLogger.cpp): defines 4 functions for a subclass
* [LogSingleton.cpp](/CS1337/HW5/src/LogSingleton.cpp): defines 4 of 5 functions for a class

### Header Files
* [CS1337Logger.h](/CS1337/HW5/src/CS1337Logger.h): contains the class definition of the abstract base class, including 2 inline functions and 1 pure virtual function defined in subclasses
* [FileLogger.h](/CS1337/HW5/src/FileLogger.h): contains the class definition of a subclass
* [ScreenLogger.h](/CS1337/HW5/src/ScreenLogger.h): contains the class definition of a subclass
* [LogSingleton.h](/CS1337/HW5/src/LogSingleton.h): contains the class definition of a class, including 1 inline function

## Output File
* [Log.txt](/CS1337/HW5/Log.txt): output file
