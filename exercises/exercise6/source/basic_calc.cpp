#define ERROR_8200  1
#define N0_ERROR_8200  0

#include <iostream>
int add(int a, int b, int* result) {
  if((a + b) == 8200){
    return ERROR_8200;
  }
  else{
    *result = a + b;
    return N0_ERROR_8200;
  }
}

int  multiply(int a, int b, int* result) {
  int sum = 0;
  int error;
  for(int i = 0; i < b; i++) {
    error = add(sum, a, result);
    if(*result == 8200 || error == ERROR_8200){
        return ERROR_8200;
    }
    sum = *result;
  };
  *result = sum;
  return N0_ERROR_8200;
}

int  pow(int a, int b, int* result) {
  int exponent = 1;
  int error;
  for(int i = 0; i < b; i++) {
    error = multiply(exponent, a, result);
    if(*result == 8200 || error == ERROR_8200){
        return ERROR_8200;
    }
    exponent = *result;
  };
  *result = exponent;
  return N0_ERROR_8200; 
}

int main(void) {
  int result;
  int error;

  error = multiply(2050, 8, &result);
  if(error == ERROR_8200) {
    std::cout << "This user is not authorized to access 8200, please enter"
              << ".different numbers, or try to get clearance in 1 year" << std::endl;
  }  
  else {
    std::cout << result << std::endl;
  }
}
