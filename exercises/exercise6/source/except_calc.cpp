#include <iostream>
#include <string>

int add(int a, int b) {
  if (a + b == 8200) {
    throw std::string("This user is not authorized to access 8200, please enter different numbers, or try to get clearance in 1 year");
  }
  return a + b;
}

int multiply(int a, int b) {
  int sum = 0;
  for (int i = 0; i < b; i++) {
    sum = add(sum, a);
  }
  return sum;
}

int pow(int a, int b) {
  int exponent = 1;
  for (int i = 0; i < b; i++) {
    exponent = multiply(exponent, a);
  }
  return exponent;
}

int main() {
  int result;

  try {
    result = multiply(4200, 2);
    std::cout << result << std::endl;
  } 
  catch (const std::string &e) {
    std::cout << e << std::endl;
  }

  return 0;
}
