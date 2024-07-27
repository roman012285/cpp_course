#include "ShiftText.h"

#include<iostream>
#include<cstring>

using std::string;
using std::cout;
using std::endl;

ShiftText::ShiftText(std::string text, int key)
    : PlainText(text), _key(key) {
    _text = encrypt(_text, _key); // Encrypt the text during initialization
}

ShiftText::~ShiftText(){};

std::string ShiftText::encrypt(std::string text, int key) {
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {  
            text[i] = (text[i] - 'a' + key) % 26 + 'a';  
        }
            // Non-letter characters are not changed
    }
    return text;
}

std::string ShiftText::decrypt(std::string text, int key) {
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {  
            int shifted = text[i] - 'a' - key;  
            if (shifted < 0) {
                shifted += 26;  
            }
            text[i] = shifted % 26 + 'a';  
        }
            // Non-letter characters are not changed
    }
    return text;
}

std::string ShiftText::encrypt(){
    if(_isEncrypted == false){
        _text = encrypt(_text, _key);
    }
    _isEncrypted = true;
    return _text;
}

std::string ShiftText::decrypt(){
    if(_isEncrypted == true) {
        _text = decrypt(_text, _key);
    }
    _isEncrypted = false;
    return _text;
}


