## Templates
- Assume we want to write the following function
```
void swap(int& num1, int& num2)
{
      int temp = num1;
    num1 = num2;
    num2 = temp;
}
```
- Now assume we want to swap another types. Than we can solve it by:
* Function overloading
* Using void type
```
void swap(void* first, void* second, int size)
{
    void* temp = malloc(size);
    std::memcpy(temp, first, size);
    std::memcpy(first, second, size);
    std::memcpy(second, temp, size);
    free(temp);
}
```
* Using macros
```
#define swap(x, y, T) {T temp = (x); (x) = (y); (y) = temp;}

void main()
{
     int num1 = 3;
    int num2 = 10;
    char c = 'E’;

    swap(num1, num2, int);
    swap(num1, c, int);
}
```
The code will be replaced to:
```
void main()
{
     int num1 = 3;
    int num2 = 10;
    char c = 'E’;

    {int temp = (num1); (num1) = (num2); (num2) = temp; }
    {int temp = (num1); (num1) = (c); (c) = temp; }
}
```
 - The disadvantages of those methods is they don't have any control on the variables and may cause run time error.

 ### Function templates (functions that can receive "any" type)
 We define template
 ```
 template <class T>
 void swap(T& first, T& second)
 {
     T temp = first;
     first = second;
     second = temp;
 }
 
 // the usage is
 void main()
 {
     int x = 10;
     int y = 20;
 
     // stepping out of the global namespace
     ::swap(x, y); 
 }
 ```

 - Another great example:
 ```
 #include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 10;
    int y = 20;

    double d1 = 5.67;
    double d2 = 9.23;

    char c1 = 'a';
    char c2 = 'z';

    // Using the max template with different data types
    std::cout << "Max of " << x << " and " << y << " is " << max(x, y) << std::endl;
    std::cout << "Max of " << d1 << " and " << d2 << " is " << max(d1, d2) << std::endl;
    std::cout << "Max of '" << c1 << "' and '" << c2 << "' is '" << max(c1, c2) << "'" << std::endl;

    return 0;
}
```
* We ise `::` when the template located inside a class or different namespace
- Important : The compiler generated new function based on the arguments we send. If we do not call the function than the compiler will ignore the template. Generally speaking, if we do not use the template we can write it with syntax error and the compiler wont throw any errors

- In some cases we can direct the compiler explicitly what will be the types for example:
```
template <class T1, class T2>
T1 f(int i)
{
    T2 temp;
    T1 c;

    // code...
    return c;
}

// Using the template
int main()
{
     std::string m = f < std::string, float>(76);    
   return 0; 
}

```
 ### Class templates 
 - Used to store data for example vectors
```
// declaration
template <class Item>
class MyStack
{
private:
    std::vector<Item> _items;
public:
    Item pop();
    void push(Item x);
};

// the implementation

template <class Item>
Item MyStack<Item>::pop()
{
    // code
}

template <class Item>
void MyStack<Item>::push(Item x)
{
    // code
}

void main()
{
    MyStack<int> s;
    s.push(12);
}

```
- Important: We will define the class template implementation and declaration in `.h` file
