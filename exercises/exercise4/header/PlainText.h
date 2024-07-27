#pragma once
#include<string>

class PlainText{

protected:
    std::string _text;
    bool _isEncrypted;

public:  
    PlainText(std::string text); // constructor
    ~PlainText(); // destructor
    bool isEncrypted() const;
    std::string getText() const;
};





