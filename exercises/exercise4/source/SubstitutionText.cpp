#include "SubstitutionText.h"

#include<iostream>
#include<fstream>

using std::string;
using std::cout;
using std::endl;

SubstitutionText::SubstitutionText(string text, string dictionaryFileName) 
    :PlainText(text) {
     _text = encrypt(_text, "dictionary");
};


SubstitutionText::~SubstitutionText() {
    // add any desired code 
}

string SubstitutionText::encrypt(string text, string dictionaryFileName){
    std::ifstream myFile;
    string fName = dictionaryFileName + ".csv";
    myFile.open(fName);

    if(!myFile){
        cout << "ERROR" << endl;
        exit(1);
    }
    string line;
    for(int i=0; i<text.length(); i++){
        if(text[i] >='a' && text[i] <= 'z') {
            while(std::getline(myFile, line)){
                if(line[0] == text[i]){
                   text[i] = line[2]; 
                   continue;
                }
            }//while
        }//for
        // do nothing
    }
    myFile.close();
    return text;
}

string SubstitutionText::decrypt(string text, string dictionaryFileName){
    std::ifstream myFile;
    string fName = dictionaryFileName + ".csv";
    myFile.open(fName);

    if(!myFile){
        cout << "ERROR" << endl;
        exit(1);
    }
    string line;
    for(int i=0; i<text.length(); i++){
        if(text[i] >='a' && text[i] <= 'z') {
            while(std::getline(myFile, line)){
                if(line[2] == text[i]){
                   text[i] = line[0]; 
                   continue;
                }
            }//while
        }//for
        // do nothing
    }
    myFile.close();
    return text;
}

string SubstitutionText::encrypt() {
     _isEncrypted = true;
    _text = encrypt(_text, "dictionary");
    return _text;
}

string SubstitutionText::decrypt() {
     _isEncrypted = false;
    _text = decrypt(_text, "dictionary");
    return _text;

}



