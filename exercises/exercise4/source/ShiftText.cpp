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

ShiftText::~ShiftText(){
    cout << "destructor of ShiftTextClass activated" << endl;
}

std::string encrypt(std::string text, int key) {
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {  
            text[i] = (text[i] - 'a' + key) % 26 + 'a';  
        }
            // Non-letter characters are not changed
    }
    return text;
}

std::string decrypt(std::string text, int key) {
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
    _isEncrypted = true;
    _text = encrypt(_text, _key);
    return _text;
}

std::string ShiftText::encrypt(){
    _isEncrypted = false;
    _text = decrypt(_text, _key);
    return _text;
}


