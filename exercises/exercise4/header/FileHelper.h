#pragma once
#include<string>

using std::string;

class FileHelper {

public:
    static string readFileToString(string fileName);
    static void writeWordsToFile(string inputFileName, string outputFileName);
    static void saveTextInFile(string text, string outputFileName);

};

