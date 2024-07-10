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
 
 ## `this` pointer
 - `this` is a pointer that points to the object that called the method 
 - The function we defined previously as `void print() const;` interpreted by the compiler and equivalent to `void print(Student* this) const;`
 - In the main, the compiler transforms `stud1.print()` to `Student::print(&stud1)`

 ## Encapsulation
 - We decide which of the fields or methods we want to hide from the user.
 - `public` - possible to access them from any place
 - `private` - possible to acces them only from `namespace`.
 - Impossible to access them outside the Class. 
 - **IMPORTANT** : fields will always be private and, methods will always be public
 
 ## Getters and Setters
-  Get is used to get the field value outside the Class (remember that fields are private)
- Set will give us the ability to change the fields.

```
#include <string>
#define NUM_OF_GRADES 4
 
class Student 
{
public:
    // methods
    double getAverage() const;
    void print() const;
 
private:
    // fields
    int _id;
    std::string _firstName;
    std::string _lastName;
    unsigned int _grades[NUM_OF_GRADES];
 
    //methods
    std::string getGradeString(const int gradeIndex) const;	// helper method
 
};

```
- note that helping methods can also be defined as private

- Getter declaration maybe like:  
```
unsigned int* getGrades() const; // we don't want to change the value than we add const
```
- Setter declaration maybe like:
```
// note that we do not add const since it change fields value
void setId(const int newId);
void setFirstName(const std::string newFirstName);
void setLastName(const std::string newLastName);
void setHeight(const int newHeight);
void setGrade(const int grade_idx, const unsigned int new_grade);
```

- Setter implementation maybe like
```
void Student::setGrade(const int grade_idx, const unsigned int new_grade)
{
    if (grade_idx >= NUM_OF_GRADES || grade_idx < 0)
    {
        std::cerr << "grade index must be between 0 to 3" << endl;
        _exit(1)
    }
    if (new_grade < 0 || new_grade > 100)
    {
        // writes to cerr - a stream dedicated to error audit
        std::cerr << "grade must be between 0 to 100" << endl;
    }
    else
    {
        this->_grades[grade_idx] = new_grade;
    }
}

```
- After define the setters we can only change the field thought the setter
`stud1.id = 10;` - ERROR
`stud1.setGrade(0, 78);` - FINE

## Complex definitions of Classes
```
#include "Student.h"
 
#define MAX_STUDENTS_IN_CLASS 10
 
class ClassRoom
{
public: 
    void init();
    void printStudents() const;
    void addStudent(const Student stud);
private:
    Student _studentsInClass[MAX_STUDENTS_IN_CLASS]; // array where each element is from student object
};
```

### Bonus information
### Reference operator `&`

- A reference is an alias for another variable, which means it essentially acts as another name for that variable. Here’s a detailed explanation of references using the `&` operator:
```
int x = 10;
int &ref = x;

ref = 20;
std::cout << x << std::endl; // The value of x is 20
```

 - References are often used to pass arguments to functions. This is particularly useful for large objects to avoid copying them
 ```
 void incrementNum(int& num){

    num++;
 }

 int main() {
    int a = 5;
    incrementNum(a);
    std::cout << a;  // a = 6

    return 0;
 }
 ```
- Functions can return references to allow modifications to the returned variable.
```
int& getReference(int &num) {
    return num;
}

int main() {
    int b = 10;
    int &refToB = getReference(b);
    refToB = 15;  // Changes the value of b to 15
    std::cout << b;  // Outputs: 15
    return 0;
}
```

### Notes and comparison to pointers
- References must always refer to a valid object and cannot be null. 
- Pointers can be null.   

- References cannot be reassigned to refer to a different object after they are initialized.
- Pointers can be reassigned to point to different objects.   


 ## Coding style
 - Classes starts with big letter
 for example: `Class Student`
 - Instances will start with small letter 
 for example: `Student stu`
 - Methods and fields (also function names and variables) will start with small letter
 for example: `getGrade`, `calcAverageMark`