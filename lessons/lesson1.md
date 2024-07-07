# Introduction to OOP in CPP

- Class functions will be called methods in OOP
- Class variables will be called attributes/fields in OOP

### Basic exercise
- The goal of the exercise is to decide which classes and attributes required to design a tool that presents the grades of students
- The are 4 subjects : History, Literature, Math and English
- Each student has a name, average grade, grade at each subject and Id.
- Each class has 10 students
- TODO: 
what classes are required?
what fields must be included?
what methods must be included(what they accept and return)?

### Solution

1. Class student:
   <u> fields </u>  
   unsigned int id;
   unsigned int grade[4];
   string name;
   <u> methods </u>
   update id. Accepts the id number
   update name. Accepts the name
   update grade. Accepts the grade and subject
   calc average. Return the calculated average.

2. Class the class
    <u> fields </u>
    unsigned int class_number;
    array of 10 each element is of class student
    <u> methods </u>
    print student. Accepts the class id and the student information

## Definition of classes in CPP - **usually in header file**
```
class Student {
    public:

};
```
- Note that name of the class starts with capital letter.

## Definition of methods and fields in CPP - **usually in header file**
```
#include <string>

# define NUM_OF_GRADES 4

class Student {
    public:

        // fields
        int id;
        std::string firstName;
        std::string lastName;
        unsigned int grades[NUM_OF_GRADES];
        
        // methods
        double getAverage() const;
        void print() const;
        void printGrade(const int gradeIndex) const; // helper method

};
```
- The name `const` at the end of each method means that the method wont be able to change the student fields

## Definition of methods and fields in CPP - **usually in CPP file**
```
#include "Student.h"

double Student::getAverage() const {
    // method code
}
```
- `double Student::getAverage() const`. double it hte returned value. the `::` means we are accessing the namespace of a Class Student.
- if the method used `const` than it must be defined with that keyword in the `Student.cpp`
- the return type is not a part of the method prototype

## Instantiates of a Class - Objects
- The instance is something that stored in the memory
- Each new object will allocate memory for its fields
- The methods of different objects of the same Class will be defined only once.
```
#include "Student.h"

int main(){

    Student stud1;
    // first student info
    stud1.firstName = "Shahar";
    stud2.LastName = "Hasson";
    stud1.id = 123456789;
    stud1.grades[0] = 90;
    stud1.grades[1] = 80;
    stud1.grades[2] = 70;
    stud1.grades[3] = 60;

    std1.print();
    std::cout << "The average grade is: << stud1.getAverage << std::endl;

    Student stud2;
    // second student info
    stud2.firstName = "John";
    stud2.LastName = "Doe";
    stud2.id = 987654321;
    stud2.grades[0] = 80;
    stud2.grades[1] = 70;
    stud2.grades[2] = 60;
    stud2.grades[3] = 50;

    std2.print();
    std::cout << "The average grade is: << stud2.getAverage << std::endl;
    return 0;
}
```
 

 ## Coding style
 - Classes starts with big letter
 for example: `Class Student`
 - Instances will start with small letter 
 for example: `Student stu`
 - Methods and fields (also function names and variables) will start with small letter
 for example: `getGrade`, `calcAverageMark`