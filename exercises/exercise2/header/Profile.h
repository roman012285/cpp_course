#pragma once

#include "Page.h"
#include "UserList.h"

class Profile {

public:
    void init(User owner);
    void clear();
    void addPostToProfilePage(std::string post);
    void addFriend(User friend_to_add);

    //getters
    User getOwner() const;
    std::string getPage() const;
    std::string getFriends() const;
    std::string getFriendsWithSameNameLength() const;

    //setters
    User setStatus(std::string new_string);


private:
    User _user;
    Page _page;
    UserList _userList;

};