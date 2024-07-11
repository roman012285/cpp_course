#pragma once
#include<string>

class Page {

public:
    void init();
    void clearPage();
    void addLineToPosts(std::string new_line);
    
    //getters
    std::string getPosts() const;
    std::string getStatus() const;

    //setters
    void setStatus(std::string status);


private:
    std::string _status;
    std::string _posts;

};