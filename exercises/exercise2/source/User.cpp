
#include "User.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

void User:: init(unsigned int id, std::string username, unsigned int age) {

    this->_id = id;
    this->_userName = username;
    this->_age = age;

}

unsigned int User::getID() const {
    return this->_id;
}

std::string User::getUserName() const{
    return this->_userName;
}

unsigned int User::getAge() const{
    return this->_age;
}

DevicesList& User::getDevices(){
    return this->_devicesList;
}
