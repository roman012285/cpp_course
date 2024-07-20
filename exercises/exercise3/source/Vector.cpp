#include "Vector.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

Vector::Vector(int n){
    if (n < 2) {
        n = 2;
    }

    this-> _elements = new int[n];
    this-> _size = 0;
    this->_capacity = n;
    this-> _resizeFactor = n;
}

Vector::~Vector() {
    delete[] _elements;
    this->_elements = nullptr;
}

int Vector::size() const {

    return this->_size;

}

int Vector::capacity() const {

    return this->_capacity;

}

int Vector::resizeFactor() const {

    return this->_resizeFactor;

}

bool Vector::empty() const {

    if((this->_size == 0) || (this->_elements == nullptr)) {
        return true;
    }

    else {
        return false;
    }

}

void Vector::assign(const int val){
    for(int i=0; i < this->size() ; i++){
        this->_elements[i] = val;
    }
}

void Vector::reserve(const int n) {
    if (n < this->capacity())
        return;

    // calculate the times of resize addition
    int resizeMultiplier = (n - this->capacity())/this->resizeFactor() + 1;
    
    // define the new array size
    int newSize = this->capacity() + this->resizeFactor()*resizeMultiplier;
    int* newData = new int[newSize];

    // copy and delete the previous arr
    for(int i=0; i < this->size() ; i++){
        newData[i] = _elements[i];
    }

    delete[] _elements;    
    _elements = newData;


    // update _capacity
    this->_capacity = newSize;

}

void Vector::push_back(const int& val) {
    if(this->size() < this->capacity()) {
        _elements[this->size()] = val;
        this->_size++;
        return;
    }
    
    // increase the capacity by resizeFactor when no capacity left
    int newSize = this->capacity() + this->resizeFactor();
    int* newData = new int[newSize];

    // copy and delete the previous arr
    for(int i=0; i < this->size() ; i++){
        newData[i] = _elements[i];
    }
    
    delete[] _elements;
    _elements = newData;

    // add the new single element to the end
    this->_elements[this->size()] = val;
    this->_size++;

    

    // update _capacity
    this->_capacity = newSize;

}

int Vector::pop_back(){
    if (this->size() == 0) {
        std::cout << "error: pop from empty vector" << endl;
        return -9999;
    }

    this->_size = this->size() - 1;
    return _elements[this->size()];
    
}

void Vector::resize(const int n){
    if(n == this->size()){
        return;
    }

    if(n < this->size()) {
        this->_size = n;
        return;
    }

    this->reserve(n);
    this->_size = n;

}

void Vector::resize(const int n, const int& val){
    int tempSize = this->size();

    this->resize(n);

    if(n > tempSize){
        for(int i= tempSize; i < n; i++){
            this->_elements[i] = val;
        }
    }

}


Vector::Vector(const Vector& other){
    this->_capacity = other._capacity;
    this->_size = other._size;
    this->_resizeFactor = other._resizeFactor;

    // performs deep copy
    this->_elements = new int[other._capacity];
    for(int i = 0; i < other._size; i++){
        this->_elements[i] = other._elements[i];
    }

}

Vector& Vector::operator=(const Vector& other) {
    // Self-assignment check
    if (this == &other) { // this is a pointer and that why we use '&` before other
        return *this;
    }

    // Release the existing memory
    delete[] this->_elements;

    // Allocate new memory based on the size of the other vector
    this->_elements = new int[other._capacity];

    // Copy the elements from the other vector
    for (int i = 0; i < other._size; ++i) {
        this->_elements[i] = other._elements[i];
    }

    // Update metadata
    this->_size = other._size;
    this->_capacity = other._capacity;
    this->_resizeFactor = other._resizeFactor;

    return *this; 
}

	const int& Vector::operator[](int n) const {
    if(n < 0 || n > this->_size-1) {
        cerr << "access is out of boundaries!!!" << endl;
        return this->_elements[0];
    }
    else {
        return this->_elements[n];
    }
}