#pragma once
#include <string>
#include "Device.h"
#include "DeviceList.h"

class User {

public:
    void init(unsigned int id, std::string username, unsigned int age);
    void clear();
    bool checkIfDeviceAreOn() const;

    // getters
    unsigned int getID() const;
    std::string getUserName() const;
    unsigned int getAge() const;
    DevicesList& getDevices();
    void addDevice(Device newDevice);


private:
    unsigned int _id;
    std::string _userName; 
    unsigned int _age;   
    DevicesList _devicesList;    


};