#include "FileHelper.h"
#include<iostream>
#include<fstream>


using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

string FileHelper::readFileToString(string fileName) {
    string stringToReturn = "";
    string temp;
    ifstream fileToRead("exercises/exercise4/source/" + fileName);
    if (!fileToRead.is_open()) {
        cout << "Error opening file in readFileToString method" << endl;
        exit(1);
    }

    while (std::getline(fileToRead, temp)) {
        stringToReturn += temp;
        if (fileToRead.peek() != EOF) {
            stringToReturn += "\n";
        }
    }

    fileToRead.close();
    return stringToReturn;
}

void FileHelper::writeWordsToFile(string inputFileName, string outputFileName) {
    ifstream inputFile;
    inputFile.open("exercises/exercise4/source/" + inputFileName);

    if (!inputFile.is_open()) {
        cout << "Error: Could not open input file: " << inputFileName << endl;
        return;
    }

    ofstream outputFile;
    outputFile.open("exercises/exercise4/source/" + outputFileName);

    if (!outputFile.is_open()) {
        cout << "Error: Could not open or create output file: " << outputFileName << endl;
        return;
    }

    string word;
    while (inputFile >> word) {
        outputFile << word;
        if (inputFile.peek() != EOF) {
            outputFile << endl;
        }
    }

    inputFile.close();
    outputFile.close();
}

void FileHelper::saveTextInFile(string text, string outputFileName){
    ofstream outputFile;
    outputFile.open("exercises/exercise4/source/" + outputFileName);
    
    if (!outputFile.is_open()) {
        cout << "Error: Could not open or create output file: " << outputFileName << endl;
        return;
    }

    outputFile << text;
    outputFile.close();
    
}