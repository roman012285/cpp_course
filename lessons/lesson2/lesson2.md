# Introduction to OOP in CPP - continue


## Constructor
- Function that activated **only** at the moment we create an object (there is no need to call her explicitly)  and used for initialization of the fields and memory initialization.   
The function is activated only once and automatically. There is no option to call her again explicitly.
- Properties : the function name is the same as class name
- Do not return anything
- Can accept parameters
### Default constructor
- when we do not define a contractor in explicit way, than default constructor is inferred. It do not accepts anything and do nothing
### Copy constructor
- when we define a class we get some sort of a free constructor that allow us to copy fields from one object to another from the same class 
- The default copy constructor copies all the fields from one to another. Note that if one of the fields is a pointer than it copies the pointer so changing one fields in some object will effect the other to.

```
int main()
{
    Student A(123456789, "Blinky", "Bill");
    cout << "Student A info" << endl;
    A.print();
    cout << "\n" << endl;

    // creates Student object B by copying A
    Student B(A);
    cout << "Student B info" << endl;
    B.print();
    cout << "\n" << endl;

    A.setGrade(HISTORY_GRADE_IDX, 60);
    B.setId(987654321);
    cout << "changed Student A History grade to 60,
                and B id to 987654321" << endl;

    cout << "Student A info" << endl;
    A.print();
    cout << "\n" << endl;

    cout << "Student B info" << endl;
    B.print();
    cout << "\n" << endl;

    system("pause");
    return 0;
}
```
- Definition of copy constructor (once we want to define ourself and not the default one)
```
// <Class name> (const <class name> & <the object we copy from>)
Student(const Student& other);
```
## Destructor
- FUnction that activated when we delete the object. The function is executed in automat and there is no need to call her explicitly.
- Properties: Function name is the class name with `~` in front of it.
- Do not return anything
- Do not accept parameters
- The function is used to free resources
- **In contrast to constructors** that function can be called explicitly.

## Function overloading
- Mechanism that allows us to define functions with the same name only with different prototype(name + argument type)
- THe return parameter is not a part of the function prototype.

```
void print();
void print(int a);
void print(char a);
void print(std::string s, int a );
```
- refer to `/finalFiles/funcOvd.cpp` for example

## Constructor overloading
- usually function overloading is usually used in context of constructor overloading
```
#include <string>

class Screen
{
private:
    std::string _name;
    int _id;
public:
    Screen();
    Screen(std::string name);
    Screen(std::string name, int id);
    void showDetails();
};

int main()
{
    // no need to use parentheses 
    Screen s1;
    s1.showDetails();
 
    Screen s2("Philips_Z12");
    s2.showDetails();
 
    Screen s3("Philips_Z12", 32);
    s3.showDetails();
}

```
## Operator overload
- We can use `==` or `>` and so on between objects. We have to define what they do
```
_ **Important** each operator  must have a special signature which we cant decide. We have to look in google to find it
bool Student::operator==(const Student& other) const
{
	return this->_id == other._id;
}
```
- For more operator refer to `/finalFiles/Student.cpp`
