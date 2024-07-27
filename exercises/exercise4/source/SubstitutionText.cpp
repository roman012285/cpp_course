#include "SubstitutionText.h"

#include<iostream>
#include<fstream>

using std::string;
using std::cout;
using std::endl;

SubstitutionText::SubstitutionText(string text, string dictionaryFileName) 
    :PlainText(text), _dictionaryFileName(dictionaryFileName) {
     _text = encrypt(_text, dictionaryFileName);
};


SubstitutionText::~SubstitutionText() {
    // add any desired code 
}

string SubstitutionText::encrypt(string text, string dictionaryFileName){
    std::ifstream myFile;
    myFile.open("exercises/exercise4/source/" + dictionaryFileName);

    if(!myFile.is_open()){
        cout << "error opening " << dictionaryFileName << endl;
        exit(1);
    }
    string line;
    for(int i=0; i<text.length(); i++){
        if(text[i] >='a' && text[i] <= 'z') {
            while(std::getline(myFile, line)){
                if(line.length() >= 3 && line[1] == ',' && line[0] == text[i]){
                   text[i] = line[2]; 
                   break;
                }
            }//while
            myFile.seekg(0, std::ios::beg); // Move the pointer to the start
        }//for
        // do nothing
    }
    myFile.close();
    return text;
}

string SubstitutionText::decrypt(string text, string dictionaryFileName){
    std::ifstream myFile;
    myFile.open("exercises/exercise4/source/" + dictionaryFileName);

    if(!myFile){
        cout << "error opening " << dictionaryFileName << endl;
        exit(1);
    }
    string line;
    for(int i=0; i<text.length(); i++){
        if(text[i] >='a' && text[i] <= 'z') {
            while(std::getline(myFile, line)){
                if(line.length() >= 3 && line[1] == ',' && line[2] == text[i]){
                   text[i] = line[0]; 
                   break;
                }
            }//while
            myFile.seekg(0, std::ios::beg); // Move the pointer to the start
        }//for
        // do nothing
    }
    myFile.close();
    return text;
}

string SubstitutionText::encrypt() {
    if(_isEncrypted == false){
        _text = encrypt(_text, _dictionaryFileName);
    }
    _isEncrypted = true;
    return _text;
}

string SubstitutionText::decrypt() {
    if(_isEncrypted == true){
        _text = decrypt(_text, _dictionaryFileName);
    }
    _isEncrypted = false;
    return _text;

}



