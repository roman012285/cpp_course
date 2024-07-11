#include "Page.h"

#include <iostream>
using std::cout;
using std::endl;

void Page::init(){
   this->clearPage();
   this->_status.clear();

}

std::string Page::getStatus() const{
    return this->_status;
}

void Page::clearPage() {
    this->_posts.clear(); // makes the string to be empty
}


void Page::setStatus(std::string status) {
    this->_status = status;
}

void Page::addLineToPosts(std::string new_line){
    this->_posts = this->_posts + new_line + "\n";
}

std::string Page::getPosts() const{
    cout << _posts << endl;
}