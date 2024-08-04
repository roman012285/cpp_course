## Environment in C++ Course
- To run the code in this repository, you need to have a C++ compiler installed on your machine.
- Please follow the link to install the C++ compiler on your machine. [Install C++ compiler](https://code.visualstudio.com/docs/cpp/config-mingw)

## Folder organization
- Each exercise is in a separate folder. It has `Source` and `Header` files located at specific locations in each exercise.
- To build the code please type
```
./build.py -dir exercise<num> -test <file_name_with_main>
```

- To run the code please type
```
./build.py -dir exercise<num> -run -test <file_name_with_main>
```
That script will generate `build` folder including executable file and object files.

## Lessons
- **Lesson1** - Intro to OOP in C++
- **Lesson2** - Introduction to OOP in C++ continue
    * Constructors
    * Destructors
    * Default constructor
    * Copy constructor
    * Deep copy VS Shallow copy
    * Initialization line
    * Function overloading
    * Constructors overloading
    * Operator overloading 
- **Lesson3** - Inheritance, Compositions and Multiple Inheritance
- **Lesson4** - Polymorphism
    * Polymorphism
    * Virtual functions
    * Function pointers
    * Override
    * Pure Virtual functions
    * Abstract classes
- **Lesson5** - Exceptions and Debug



## assignments
- assignment1 - Linked list implementation
- assignment2 - Design a basic social network.       
for test run  `./build.py -dir exercise2 -test Tester -run`
- assignment3 - Design a vector structure.     
for test run  `./build.py -dir exercise3 -test <test_file> -run`
- assignment4 - Encryption and decryption. 
- assignment5 - Draw figures.      
 