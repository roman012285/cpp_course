#pragma once
#include <string>

///////////////////////////////////////////////////////////
/*														 //
	Those definitions are used for tests,                //
	you can add your own, but please do not delete any.  //
*/														 //
enum DeviceType {PHONE, PC, LAPTOP, TABLET};		     //
													     //
#define UbuntuOS "UbuntuLinux"                           //						
#define RedHatOS "RedHatLinux"							 //
#define MacOS "MacOS"									 //
#define IOS "IOS"										 //
#define WINDOWS7 "Windows7"                              //
#define WINDOWS10 "Windows10"                            //
#define WINDOWS11 "Windows11"                            //
#define ANDROID "Android"                                //
													     //
/// ///////////////////////////////////////////////////////


class Device
{

public:

    // methods
    void init(unsigned int id, DeviceType type, std::string os);
    void activate();
    void deactivate();

    //getters
    std::string getOS() const;
    unsigned int getID() const;
    DeviceType getType() const;
    bool isActive() const;

private:
    //fields
    std::string _os;
    unsigned int _id;
    DeviceType _type;
    bool _activeState;

};

