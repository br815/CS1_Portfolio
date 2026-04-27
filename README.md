<!-- To preview this markdown file in VSCode: Ctrl+Shift+V -->

# CS1 Portfolio | Bushra Rahman
## CS 1337 (Computer Science I) | UTD Fall 2019
GitHub Pages link: https://br815.github.io/CS1_Portfolio/

This repository contains university programming assignments from my [Computer Science I course](/CS1337).

The purpose of this repository is archival and educational:
- to track my progress learning C and C++
- to practice writing clear, correct, and well-structured code
- to reflect on design decisions and showcase my improved understanding of the language

## Highlights
- Control structures and structured data types
- Basic algorithmic searching and sorting techniques
- Object-oriented design, defining and using classes
- Programming paradigms and design patterns
- Structured data types and memory management techniques in C and C++

## Instructions to Install MinGW
Compilers for C and C++ are necessary to run these assignments (eg. the `gcc` and `g++` compilers in MinGW, a Microsoft Windows port of the GNU Compiler Collection).

To install MinGW on Windows 11 or less, follow [these instructions](/CS1337/Eclipse_for_Windows_with_MinGW.pdf) (refer to Pages 3-4 of the linked PDF):
1. Download the latest version of the MinGW installer from [this SourceForge link](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/).
2. Run the installer. On the second installer screen, make sure to select the `X86_64` architecture. Don’t make any other changes with the installer.
3. Add the MinGW compiler the `Path` Environment Variable. [This YouTube video](https://www.youtube.com/watch?v=uadGsNA6h5Q) has the steps to follow:
    * Open `Control Panel >> System and Security >> System >> Advanced System Settings`.\
    (Alternatively, open `Settings >> System >> About >> Advanced System Settings`.)\
    This opens a window for `System Properties`.
    * In `System Properties`, go to `Environment Variables`.\
    In `Environment Variables`, look down at `System variables` and scroll until you reach `Path`.\
    Select `Path` and hit `Edit`.
    * Once you’ve opened `Edit environment variable`, find the file path for MinGW’s `/bin` folder in your File Explorer and copy it.\
    It should look similar to:
    <!-- CODE START -->
    ```
    C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin
    ```
    <!-- CODE END -->
    * Go back to `Edit environment variable`, hit `New`, and paste the file path for `/bin`.
    * Then hit `OK` in `Edit environment variable`, hit `OK` in `Environment Variables`, and hit `OK` in `System Properties`.
    * MinGW should now be properly installed and locatable within `Path`. To test in Command Prompt, run:
    <!-- CODE START -->
    ```
    g++ --version
    ```
    <!-- CODE END -->
    You should see output similar to:
    <!-- CODE START -->
    ```
    g++ (MinGW.org GCC-6.3.0-1) 6.3.0
    Copyright (C) 2016 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    ```
    <!-- CODE END -->
    Run `gcc --version` to see similar output for the C compiler.

After installing MinGW and adding it to `Path`, make sure to restart your IDE to avoid compilation errors.

## C and C++ Compilation & Execution Overview
(Using [HW1](/CS1337/HW1/) as an example. HW1 contains a [src](/CS1337/HW1/src/) folder,\
which contains 2 source files [main.cpp](/CS1337/HW1/src/main.cpp) and [amortize.cpp](/CS1337/HW1/src/amortize.cpp), and 1 header file [amortize.h](/CS1337/HW1/src/amortize.h).)

Open terminal in `CS1_Portfolio` and run:
<!-- CODE START -->
```
cd CS1337/HW1                   # cd to project root
mkdir build                     # make a build folder if it doesn't exist
g++ src/*.cpp -o build/HW1      # compile executable file into the build folder
build/HW1                       # provide the build folder as the path to the .exe file
```
<!-- CODE END -->
C and C++ compilation & execution can occur from anywhere through the use of relative paths, as long as the compilation instruction specifies the relative path to the `.cpp` or `.c` source files & the execution instruction specifies the relative path to the `.exe` executable file. However, execution *should* occur from the project root (because that is the conventional location from which your program should retrieve any IO files).

In order to achieve both from the project root, this compilation instruction goes through `src/` to compile all `.cpp` source files in [src](/CS1337/HW1/src/). Alternatively, each source file can be compiled individually through their paths:
<!-- CODE START -->
```
g++ src/main.cpp src/amortize.cpp -o build/HW1
```
<!-- CODE END -->
By default, C and C++ compilation produces `.exe` files directly in the same folder where compilation occurred; however, the provided compilation instruction uses the `-o` flag to produce the `.exe` file in a [build](/CS1337/HW1/build/) folder for clearer file organization.

Then, execution can occur from the project root as long as the path to the executable is specified, which for this project is through `build/`.

Technically, since compilation & execution *can* occur from anywhere as long as the user provides the necessary relative file paths to the source files & executable, execution for this project *can* also occur from within the same folder as the `.exe` file. To do so, go into `build` and execute directly:
<!-- CODE START -->
```
cd build
./HW1
```
<!-- CODE END -->
The `.` indicates the working directory as the path to the exectuable file. However, since the execution is not occurring at the project root, note that any user-provided IO files existing at the project root will have to be named using their relative paths: [`../input.txt`](/CS1337/HW1/input.txt/) or [`../output.txt`](/CS1337/HW1/output.txt). But if the names of these IO files are hard-coded into the source code without their relative paths, then execution *must* occur from the same level as those IO files, ie. the project root.

Similar compilation & execution behavior can be achieved through alternative commands, like:
<!-- CODE START -->
```
cd CS1337/HW1/src
g++ *.cpp                       # or, g++ main.cpp amortize.cpp (note that here, the default a.exe file is produced directly in src)
cd ..                           # go back to the project root
src/a.exe                       # can be executed with or without providing the .exe extension
```
<!-- CODE END -->

The same compilation & execution process can be applied to C projects; simply use `gcc` to compile all `.c` files.
<!-- CODE START -->
```
gcc *.c -o build/a.exe          # the build command requires the executable name to be specified
build/a                         # here, the .exe extention is omitted
```
<!-- CODE END -->

Note that compilation and execution can be done either...
* ...with or without providing the `.exe` extention (the code blocks above illustrate both)
* ...with a forward slash `/` or backslash `\` (the code blocks above do it with `/`)

## Homework Instructions & Readme Files
* HW 1
    * [HW 1: Introduction to Multi-File Projects](/CS1337/HW1/HW1_IntroToMultiFileProjects.pdf)
    * [HW 1 readme](/CS1337/HW1/readme.md)
* HW 2
    * [HW 2: Searching and Sorting on Arrays](/CS1337/HW2/HW2_SearchingSortingArrays.pdf)
    * [HW 2 readme](/CS1337/HW2/readme.md)
* HW3
    * [HW 3: Memory Management in C](/CS1337/HW3/HW3_MemMgmtC.pdf)
    * [HW 3 readme](/CS1337/HW3/readme.md)
* HW4
    * [HW 4: Classes, Inheritance, and Polymorphism](/CS1337/HW4/HW4_Classes.pdf)
    * [HW 4 readme](/CS1337/HW4/readme.md)
* HW5
    * [HW 5: Design Patterns](/CS1337/HW5/HW5_DesignPatterns.pdf)
    * [HW 5 readme](/CS1337/HW5/readme.md)
* HW6
    * [HW 6: Design Patterns Continued](/CS1337/HW6/HW6_DesignPatternsCont.pdf)
    * [HW 6 readme](/CS1337/HW6/readme.md)

## Notes
As a learning exercise, some of my code explores alternative designs that go beyond what was required for this course.

This code is not intended as production software.
