## Inheritance 
- Mechanism that allow us to avoid from unnecessary code duplication and extend existing classes without touching them.
- The class from which we inherit is called **base class** or `parent class` and the class the inherits is called **derive class** (child class)

### Basic syntax
```
class Parent {

 // any content

};

class child : public Parent {

    // any content

};
```
### example od LIFO
```
class SimpleStack
{
   int *_data;
   int _size;
   int _maxsize;

public:
   SimpleStack(int maxsize = 100);
   ~SimpleStack();

   int Pop();
   void Push(int value);
   bool IsEmpty() const;
};
```

- We would like to add another functionality to our LIFO by implementing `Top` operation that gives us the last element without popping it
```
Class TopStack : public SimpleStack {

    public:
        int Top(){
            int retval = Pop();
            Push(retval);
            return retval;
        }

};
```
- Think why we cant do that?
```
class TopStack : public SimpleStack
{
public:
   int Top() const
   {
      int value = _data[_size - 1];  // 0-based array
      return value;
   }
};
```
- Answer : the `_data[]` is defined as private and we can access it only from parent class. We walk talk about that issue in details right now

### Access Modifiers
- **public**    : Every one can access the fields from any class
- **private**   : Possible to access the fields only from function that implemented inside that specific class.
- **protected** : Possible to access the fields from the class itself and from the classes that inherits that specific class. 
- For more details please refer to [chatGpt](https://chatgpt.com/share/7d143e3f-237f-42f8-9a28-d0076f8e173f) or [another link](https://www.bogotobogo.com/cplusplus/private_inheritance.php)

```
class SimpleStack
{
protected:
   int *_data;
   int _size;
   int _maxsize;

public:
   SimpleStack(int maxsize = 100);
   ~SimpleStack();

   int Pop();
   void Push(int value);
   bool IsEmpty() const;
};

class TopStack : public SimpleStack
{
public:
   int Top() const
   {
      int value = _data[_size - 1];  // 0-based array
      return value;
   }
};

```

- Important - fields that not has any access modifier will be considered and private means that we wont be able to modify them outside the class. We set the fields in the base class to be protected cause we want to give an access to them only from the inherit class. Its good to use that hierarchy : protected fields in base class and public inheritance.


### Method hiding

```
#include <iostream>
using namespace std;

class Base {
public:
    void func() {
        cout << "Base::func()" << endl;
    }
    void func(int x) {
        cout << "Base::func(int) with x=" << x << endl;
    }
};

class Derived : public Base {
public:
    void func() {
        cout << "Derived::func()" << endl;
    }
};

int main() {
    Derived d;
    d.func();           // Calls Derived::func()
    // d.func(10);      // Error! Base::func(int) is hidden and not accessible.
}
```
### Constructors and Destructors
```
class DebugStack : public TopStack
{
   Logger *_logger;
public:
   DebugStack(maxsize) : 
     TopStack(maxsize), _logger(new Logger())
   {
   }

   ~DebugStack()
   {
      delete _logger;
   }

   // Pop, Push etc..
};

```
- Constructor order :
1. TopStack
2. Logger
3. DebugStuck

- Destructor order
1. DebugStuck
2. Logger
3. TopStack

### Inheritance and Composition
- Inheritance : mechanism that allows code reuse and extend it (**is-a**) relation
- Composition : allows to use exciting class but not to extend it. (**has-a** relation)

```
class Wheel
{
   /*...*/
};

class Vehicle
{
   /*...*/
};

class Car : public Vehicle
{
   Wheel wheels[4];
   /*...*/
};

```
- a car is a vehicle -> inheritance
- a car has a wheel -> composition

### More examples
```
class Window
{
   unsigned int width;
   unsigned height;
   // ...
};


class Home
{
   Window *windows;  // has-a
   // ...
};

```
class Fruit
{
   unsigned int calories;
   // ...
};

class Apple : public Fruit  // is-a
{
   // ...
};

### Multiple inheritance

```
class Donkey
{
   // ...
};

class Horse
{
   // ...
};

// a mule is-a donkey AND a horse
class Mule : public Donkey, public Horse 
{
   // ...
};

```
- Issues in multiple inheritance
```
struct Animal {
    void kick() { /* ... */ }
};

class Donkey : public Animal { /* ... */ };

class Horse : public Animal { /* ... */ };

// a mule is-a donkey AND a horse
class Mule : public Donkey, public Horse {
    // Inherits `kick` twice, leading to ambiguity
};

int main() {
    Mule m;
    m.kick();   // Ambiguous: Which `kick` to call?
    return 0;
}

```
- The main issue in your example is the diamond problem in C++, which occurs when two classes (Donkey and Horse) inherit from the same superclass (Animal), and then another class (Mule) inherits from both of these classes. This results in the Mule class inheriting the Animal class's members (in this case, the kick method) twice, once via each of its parent classes (Donkey and Horse), leading to ambiguity:

- Ambiguity in Member Access: When you try to call m.kick(), the compiler cannot determine whether to call Donkey's kick or Horse's kick because both paths provide a kick function inherited from Animal.

### Static functions
- can be called without the need to create an object from the class
 ```
 class MyMath
 {
   private:
   int _num;
   
   public:
   MyMath(int num);
   static int add(int a, int b);
 };
 ```

 ```
 int MyMath::add(int a, int b)
 {
     return a + b
 }
 ```
 
 ```
 void main()
 {
     cout << “Result of 5 + 2 = ” << MyMath::add(5,2) << endl;
     
     MyMath myMathObject(10);
     cout << “Result of 5 + 2 = ” << myMathObject.add(5,2) << endl;
 }
 
```

### Static variables
- In the implementation file we have to initialize the static variable

- Declarations: 
```
class MyMath
{
   private:
   int _num;
   static int _x

   public:
   MyMath(int num);
   static int add(int a, int b);
};
```

```
class MyMath
{
   private:
   int _num;
   static int _x

   public:
   MyMath(int num);
   static int add(int a, int b);
};
```

```
int MyMath::_x = 0
MyMath::MyMath(int num) : _num(num)
{    _x++;
    std::cout << “_x = ” << _x << std::endl
}
int MyMath::add(int a, int b)
{
    return a + b + _x
}
```

