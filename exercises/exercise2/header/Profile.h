#pragma once

#include "Page.h"
#include "UserList.h"

class Profile {

public:
    void init(User owner);
    void clear();
    void addPostToProfilePage(std::string post);
    void addFriend(User friend_to_add);
    void changeAllWordsInStatus(std::string word);
    void changeWordInStatus(std::string word_to_replace, std::string new_word);

    //getters
    User getOwner() const;
    std::string getPage() const;
    std::string getFriends() const;
    std::string getFriendsWithSameNameLength() const;
    //setters
    void setStatus(std::string new_string);


private:
    User _user;
    Page _page;
    UserList _userList;

};