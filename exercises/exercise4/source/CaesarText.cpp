#include "CaesarText.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

CaesarText::CaesarText(std::string text)
    : ShiftText(text, 3) { 
    _text = encrypt(text); 
}

CaesarText::~CaesarText() {
    cout << "Destructor of CaesarText activated" << endl;
}

std::string CaesarText::encrypt(std::string text) {
    return ShiftText::encrypt(text, 3);  // note the explicit call of the function in shiftText class
}

std::string CaesarText::decrypt(std::string text) {
    return ShiftText::decrypt(text, 3); 
}

std::string CaesarText::encrypt() {
    if(_isEncrypted == false){
        _text = encrypt(_text);
    }
    _isEncrypted = true;
    return _text;
}

std::string CaesarText::decrypt() {
    if(_isEncrypted == true){
        _text = decrypt(_text);
    }
    _isEncrypted = false;
    return _text;
}
