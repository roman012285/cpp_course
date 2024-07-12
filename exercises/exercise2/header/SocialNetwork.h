#pragma once

#include<string>
#include "Profile.h"
#include "ProfileList.h"

class SocialNetwork {

public:
    void init(std::string networkName, int minAge);
    void clear();
    bool addProfile(Profile profile_to_add);


    //getters
    std::string getNetworkName() const;
    int getMinAge() const;
    std::string getWindowsDevices() const;
    


private:
    std::string networkName;
    int minAge;
    ProfileList profileList;


};