##Polymorphism

- allows us to use different implementations each time. The choose of an object/function will be determined during run time.

-One very bad example to do that is by:
```
struct SimpleStack 
{
   void Clean() { std::cout << "SimpleStack::Clean\n"; }
};

struct DebugStack : public SimpleStack 
{
   void Clean() { std::cout << “DebugStack::Clean\n"; }
};

void GeneralStackCleaner(void *ptrStack, int type) 
{
   if (type == 0)
      ((SimpleStack*)ptrStack)->Clean();
   else if (type == 1)
      ((DebugStack*)ptrStack)->Clean();
}

int main() 
{
   DebugStack ds;
   GeneralStackCleaner(&ds, 2);   // Will cause an error cause two is not handled.
   return 0;
}

```

### Virtual functions
- Early biding : during compilation the compiler already knows which function to call.
- Dynamic biding: which function to call happens only during run time.
- **Virtual function** connected during run-time only in dynamic biding. 

```
class SimpleStack 
{
public:
   virtual void Clean() 
   {
      std::cout << "SimpleStack::Clean\n";
   }
};

class DebugStack : public SimpleStack 
{
public:
   virtual void Clean() 
   {
      std::cout << "DebugStack::Clean\n";
   }
};

void GeneralStackCleaner(SimpleStack *pStack) 
{
   pStack->Clean();
}

int main() 
{
   DebugStack ds;
   GeneralStackCleaner(&ds);
   return 0;
}

```

- The keyword `virtual` indicates that we are going to use rin time polymorphism
### Another polymorphism example
```
#include <iostream>

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const {
        std::cout << "Meow!" << std::endl;
    }
};

void makeAnimalSpeak(const Animal& animal) {
    animal.speak();
}

int main() {
    Dog dog;
    Cat cat;

    makeAnimalSpeak(dog);  // Output: Woof!
    makeAnimalSpeak(cat);  // Output: Meow!

    return 0;
}

```

### Function pointer
```
unsigned long func(unsigned int value)
{
   if (value < 2)
      return value;
   return func(value - 1) + func(value - 2);
}

int main()
{
   unsigned long (*func_ptr)(unsigned int) = func; 

   unsigned long result = func_ptr(7);
   std::cout << "result: " << result << std::endl;

   return 0;
}
```
```
unsigned long - the return value of the pointed function
(*func_ptr)   - name of the function pointer
(unsigned int)  - the type or input argument
```

- Array of pointers to function

```
long add(int left, int right)
{
   return left + right;
}

long mul(int left, int right)
{
   return left * right;
}

// OP is a function pointer
typedef long(*OP)(int left, int right);

int main()
{
   OP funcptr[2];
   funcptr[0] = add;
   funcptr[1] = mul;

   for (int i = 0; i < 2; i++)
      std::cout << "result:" << funcptr[i](5, 7) << std::endl;

   return 0;
}
```
- not that we have a virtual binding here because the decision which function to call is determined during run time
- Dynamic binding works on references and pointers.
- Once we declare at least one virtual function than `vptr` and `vtable` are created by the compiler
**important**
- `vptr` and `vtable` is set up by the constructor it self. Thats why we cant define constructor as `virtual` because whats defined as virtual relies on `vptr` and `vtable` thus constructor cant be virtual because it leads to `egg-chicken problem`
- Destructors, on the other hand, can and often should be virtual, especially in base classes that are intended to be inherited from. This ensures that the correct destructor is called for derived class objects, preventing resource leaks and undefined behavior.
Object Destruction:
When an object is destroyed through a base class pointer, the destructor of the most derived class should be called. This ensures that all resources allocated by the derived class are properly released.
If the destructor is not virtual, only the base class destructor will be called, potentially leading to resource leaks if the derived class has allocated resources that need to be released.

- What function should be called virtual?
In C++, the decision to declare a function as virtual typically depends on whether you expect the function to be overridden in derived classes. 
- What is `override` key word and why its used?
The override keyword in C++ is used to indicate that a member function is meant to override a virtual function in a base class. This keyword serves several important purposes:
- Purpose of the override Keyword: Ensures Correct Overriding: When you use override, the compiler checks that the function is indeed overriding a virtual function in the base class. If there is no matching virtual function in the base class, the compiler will generate an error.
This helps catch errors early, such as typos in the function name or incorrect parameter lists, which might otherwise go unnoticed.

### Object slicing
- Upcasting: casting of pointer/reference of derived class to base class. When coping an object by value and not as a pointer the upcasting will cause an object slicing
```
void IsAnyStackEmpty2(SimpleStack stack)   // copy-by-value! - SLICING
{
   bool empty = stack.IsEmpty();
   std::cout << "stack is"
             << (empty ? "" : " NOT")
             << " empty"
             << std::endl;
}

int main()
{
   TopStack tstack;
   IsAnyStackEmpty2(tstack);
   return 0;
}

```
- Here, the function `SimpleStuck::SImpleStuck will be called

### Pure virtual functions
- If function defined as pure it means that any derived class must implement it
```
class IStack
{
public:
   virtual void Pop() = 0;
   virtual void Push() = 0;
   virtual bool IsEmpty() const = 0;
};
```
- The implementation
```
#include <iostream>
#include <vector>

class SimpleStack : public IStack
{
public:
    void Pop() override {
        if (!stack.empty()) {
            stack.pop_back();
        }
    }

    void Push(int value) override {
        stack.push_back(value);
    }

    bool IsEmpty() const override {
        return stack.empty();
    }

};
```
- Class that has only pure virtual function is called `abstract class` and it cant become an object. It can only be inherited. `abstract class` is some sort of `Interfaces` like in Java

### Summary
- we will use polymorphism when at leas one function of the derived classes overrides the base class
- we will use destructor as virtual
- final example:
```
#include <iostream>

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks" << std::endl;
    }

    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
};

void makeAnimalSpeak(const Animal& animal) {
    animal.speak();
}

int main() {
    Dog dog;
    Cat cat;

    makeAnimalSpeak(dog);  // Output: Woof!
    makeAnimalSpeak(cat);  // Output: Meow!

    return 0;
}
```
- Example2 - the same functionality of the previous code but without polymorphism
```
#include <iostream>

class Animal {
public:
    void speak() const {
        std::cout << "Animal speaks" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() const {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const {
        std::cout << "Meow!" << std::endl;
    }
};

void makeDogSpeak(const Dog& dog) {
    dog.speak();
}

void makeCatSpeak(const Cat& cat) {
    cat.speak();
}

int main() {
    Dog dog;
    Cat cat;

    makeDogSpeak(dog);  // Output: Woof!
    makeCatSpeak(cat);  // Output: Meow!

    return 0;
}

```