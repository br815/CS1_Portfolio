<!-- To preview this markdown file in VSCode: Ctrl+Shift+V -->

# CS1 Portfolio - Bushra Rahman
## CS 1337 (Computer Science I) - UTD Fall 2019

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

To install MinGW on Windows 11 or less, follow [these instructions](/CS1337/Eclipse_for_Windows_with_MinGW.pdf) (jump to Pages 3-4 of the linked PDF):
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
