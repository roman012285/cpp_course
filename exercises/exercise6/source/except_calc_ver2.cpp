#include <iostream>
#include <exception>


#define FORBIDDEN_NUMBER 8200

// create new Exception base on the std::exception class.
class Exception8200 : public std::exception
{
public:
    virtual const char* what() const noexcept;
};

const char* Exception8200::what() const noexcept
{
    return "This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year";
}

int add(int a, int b) {
    if (a == FORBIDDEN_NUMBER || b == FORBIDDEN_NUMBER || a + b == FORBIDDEN_NUMBER)
    {
        // if one of the parameters or the result is 8200 we throw an error we create name Exception8200.
        throw Exception8200();
    }
    return a + b;
}

int  multiply(int a, int b) {
  int sum = 0;
  for(int i = 0; i < b; i++) {
    sum = add(sum, a);
  };
  if (a == FORBIDDEN_NUMBER || b == FORBIDDEN_NUMBER || sum == FORBIDDEN_NUMBER)
  {
      // if one of the parameters or the result is 8200 we throw an error we create name Exception8200.
      throw Exception8200();
  }
  return sum;
}

int  pow(int a, int b) {
  int exponent = 1;
  for(int i = 0; i < b; i++) {
    exponent = multiply(exponent, a);
  };
  if (a == FORBIDDEN_NUMBER || b == FORBIDDEN_NUMBER || exponent == FORBIDDEN_NUMBER)
  {
      // if one of the parameters or the result is 8200 we throw an error we create name Exception8200.
      throw Exception8200();
  }
  return exponent;
}

int main(void) {
    // check the pow func with one work example and one not.
    try
    {
        std::cout << "5^5 = " << pow(5, 5) << std::endl;
        std::cout << "8200 ^ 2 = " << pow(8200, 2) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    // check the multiply func with one work example and one not.
    try
    {
        std::cout << "5 * 5 = " << multiply(5, 5) << std::endl;
        std::cout << "8200 * 100 = " << multiply(82, 100) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    // check the add func with one work example and one not.
    try
    {
        std::cout << "4 + 8 = " << add(4, 8) << std::endl;
        std::cout << "8199 + 1 = " << add(8199, 1) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    
    

}