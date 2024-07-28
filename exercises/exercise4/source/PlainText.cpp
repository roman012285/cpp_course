#include "PlainText.h"
#include<iostream>

using std::string;
using std::cout;
using std::endl;

int PlainText::numOfTexts = 0; // initialization of static field

 PlainText:: PlainText(string text)
     :_text(text), _isEncrypted(true){ 
     numOfTexts++;  
};


 PlainText::~PlainText(){};

bool PlainText::isEncrypted() const {
    return this->_isEncrypted;
}

std::string PlainText::getText() const {
    return this->_text;
}
