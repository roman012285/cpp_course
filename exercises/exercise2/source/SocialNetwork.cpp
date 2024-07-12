#include "SocialNetwork.h"
#include<iostream>
#include <sstream> 

using std::string;

void SocialNetwork::init(std::string networkName, int minAge) {
    this->networkName = networkName;
    this->minAge = minAge;
    this->profileList.init();
}


 std::string SocialNetwork::getNetworkName() const{
    return this->networkName;
 }

int SocialNetwork::getMinAge() const{
    return this->minAge;
}

std::string SocialNetwork::getWindowsDevices() const {
    std::stringstream result;
    ProfileNode* currentProfileNode = this->profileList.get_first();
    
    bool firstEntry = true; // To handle commas correctly

    // Traverse all profiles
    while (currentProfileNode != nullptr) {
        Profile currentProfile = currentProfileNode->get_data();  // GetProfile 
        DevicesList& devicesList = currentProfile.getOwner().getDevices(); // Get list of owner profile
        DeviceNode* currentDeviceNode = devicesList.get_first(); // get first device of the owner

        // Traverse all devices in the current profile
        while (currentDeviceNode != nullptr) {
            Device currentDevice = currentDeviceNode->get_data();
            std::string os = currentDevice.getOS();

            // Check if the OS is a Windows OS
            if (os == WINDOWS7 || os == WINDOWS10 || os == WINDOWS11) {
                if (!firstEntry) {
                    result << ", ";
                }
                result << "[" << currentDevice.getID() << ", " << os << "]";
                firstEntry = false; // Subsequent entries should be preceded by a comma
            }

            currentDeviceNode = currentDeviceNode->get_next(); // iterate through owner devices
        }

        currentProfileNode = currentProfileNode->get_next(); // iterate through profiles
    }

    return result.str();
}

void SocialNetwork::clear() {
    this->profileList.clear();
}

bool SocialNetwork::addProfile(Profile profile_to_add){
    if(profile_to_add.getOwner().getAge() < (unsigned int)(this->minAge)) {
        return false;
    }
    bool addedSuccesfully;

    addedSuccesfully = this->profileList.add(profile_to_add);  
    return addedSuccesfully;
    
}