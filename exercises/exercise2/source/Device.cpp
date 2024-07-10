#include "Device.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

bool Device::isActive() const {
    return this->_activeState;
}

string Device:: getOS() const {
    return this->_os;
}

unsigned int Device::getID() const {
    return this->_id;   
}

DeviceType Device::getType() const {
    return this->_type;
}


void Device::activate() {
    this->_activeState = true;
}

void Device::deactivate() {
    this->_activeState = false;
}

void Device::init (unsigned int id, DeviceType type, std::string os) {
    this->_id = id;
    this->_type = type;
    this->_os = os;
}
