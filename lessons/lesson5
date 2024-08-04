## Exceptions
- In that part we will deal with bugs occurred during the run time. 
### throw keyword 
- keyword indicating that an exception occurred and it has to be handled.
- The exception is traveling al up the stack until the `catch` block that handles the exception

for example:

1. 
```
int subAges(const int first, const int second) {
    if (first <= 0 || second <= 0) {

	throw(std::string("Age cannot be below 0"));
    }
return abs(first - second);
}
```

- In that function when `if` is true we by typing the keyword `throw` we declare that exception occurred and must be handled some how.

2. calling the function with `throw`
```
try {
    int result = subAges(30, 20);
    std::cout << "Result: " << result << std::endl;
} 
catch (const std::string& e) {
    std::cerr << "Caught exception: " << e << std::endl;
}
```
- when `try` block calls the function it tries to catch the exception. In the above scenario the `if` of `subAges` function is not true than the function will return 10.

3. 
```
try {
    int result = subAges(0, 20);
    std::cout << "Result: " << result << std::endl;
} 
catch (const std::string& e) {
    std::cerr << "Caught exception: " << e << std::endl;
}
```
- In that case the `subAges` function throws an exceptions. The `catch` block catches it and responsible of handling it.
the output will `Caught exception: Age cannot be below 0`

- **Important** - when we throw string as a message than we will have to have catch block that catches string. Other wise it will be treated like no one catches the exception and the program will terminate

example:
1. generating exception if happened
```
void printId(int id) {
    if (id <= 0){
        throw std::string("Invalid ID");
    }
    if (id < 1000) {
        throw id;
    }
    std::cout << id << std::endl;
}
```
2.
```
int main() {
    try {
         printId(3);
    }
    catch(std::string s) {
    std::cerr << "ERROR" + s;
    }
}

```
In that case we will throw the id and since we don't have `catch` block that accepts that type than the program will terminate.

**Trick and save wheel** : By using the `catch(...)` we can catch all types
```
int main() {
    try {
         printId(3);
    }
    catch(...) {
    std::cerr << "ERROR" << std::endl;
    }
}
```

- The best way is to combine many `catch` as possible like that
```
int main()
{
    try
    {
        printId(3);
    }
    catch (const std::string e)
    {
        std::cerr << "ERROR: " << e << std::endl;
    }
    catch (const int e)
    {
        std::cerr << "ERROR: " << e << " is not a valid Id" << std::endl;
    }
    catch (...)
    {
        std::cerr << "An Error occured!" << std::endl;
    }
}

```

### User defined exceptions
- This is allowed because we can throw classes
**example**
1. definition of a class that will indicate on some error message (can be everything else) we want
```
//MyError.h;
 
#include <string>
 
class MyError
{
public:
    std::string whatWentWrong() const;
};


// MyError.cpp
 
#include <string>
 
std::string MyError::whatWentWrong() const
{
    return std::string("something went wrong!");
}

```
2. `Throw`
```
// main.cpp
 
#include "MyError.h"
  
void printValue(int num)
{
    if (num < 0)
    {
        throw MyError();
    }
    std::cout << “num is: " << num << std::endl;
}
 
//main function below

```

3. `catch`
```
// main.cpp
 
//printValue function above
  
int main()
{
    try
    {
        printValue(3);
    }
    catch (const MyError &e)
    {
        std::cout << "ERROR: " << e.whatWentWrong();
    }
}

```

- **IMPORTANT** when we throw class we have to catch it using *reference*

### Exception Library
`std:exception`
 ```
#include <iostream>
#include <exception>

class MyException : public std::exception
{
public:
    virtual const char* what() const noexcept;
};

const char* MyException::what() const noexcept
{
    return "just an example";
}

void doSomething(int value)
{
    if (value == 42)
    {
        throw MyException();
    }
}

int main()
{
    try
    {
        doSomething(42);
    }
    catch (const std::exception &e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
}

 ```
- Explanation: 
1. Custom Exception Class: MyException is derived from std::exception. It overrides the what method to return the string "just an example".

2. doSomething Function: The function doSomething takes an integer parameter value. If value is 42, it throws a MyException.

3. main Function: The main function calls doSomething(42) within a try block. Since doSomething throws a MyException when value is 42, the exception is caught by the catch block in main.
The catch block prints the error message using std::cerr. The what method of MyException is called, and it returns "just an example". The output will be: `ERROR: just an example.`

## Bugs
- Static debug - observing the code by "the eyes"
- Dynamic - in real time like (visual studio debugger)
