#include "Profile.h"

#include<iostream>
using std::cout;
using std::cin;
using std::string;

void Profile::init(User owner){
    this->_user = owner; // the user details
    this->_page.init();  // the page that belongs to the user
    this->_userList.init(); // the friend list of the user  
}

User Profile::getOwner() const {
    return this->_user;
}

User Profile::setStatus(std::string new_string) {
    this->_page.setStatus(new_string);
}


