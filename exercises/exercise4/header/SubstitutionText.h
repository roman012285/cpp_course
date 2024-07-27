#pragma once
#include<string>
#include "PlainText.h"

class SubstitutionText : public PlainText{

private:
    std::string _dictionaryFileName;

public:
    SubstitutionText(std::string text, std::string dictionaryFileName);
    ~SubstitutionText();
    static std::string encrypt(std::string text, std::string dictionaryFileName);
    static std::string decrypt(std::string text, std::string dictionaryFileName);
    std::string encrypt();
    std::string decrypt();

};