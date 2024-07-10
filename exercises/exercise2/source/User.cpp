
#include "User.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

void User:: init(unsigned int id, std::string username, unsigned int age) {

    this->_id = id;
    this->_userName = username;
    this->_age = age;
    this->_devicesList.init();

}

bool User::checkIfDevicesAreOn() const {
    DeviceNode* current = this->_devicesList.get_first();
    
    // If the list is empty, assume all devices are on (or return false based on your requirements)
    if (current == nullptr) {
        return true;
    }

    // Traverse the list and check each device's status
    while (current != nullptr) {
        if (current->get_data().isActive() == false) {
            return false; // Return false if any device is off
        }
        current = current->get_next();
    }

    return true; // All devices are on
}


DevicesList& User::getDevices() {
    return this->_devicesList;

 }

void User::clear(){
    this->_devicesList.clear();
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

void User::addDevice(Device newDevice){
    this->_devicesList.add(newDevice);

}
