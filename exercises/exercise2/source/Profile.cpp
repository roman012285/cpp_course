#include "Profile.h"

#include<iostream>
#include<string>
#include<cctype>

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

void Profile::setStatus(std::string new_string) {
    this->_page.setStatus(new_string);
}

void Profile::clear(){
    this->_userList.clear();
}

void Profile::addPostToProfilePage(std::string post) {
    this->_page.addLineToPosts(post);
}

 void Profile::addFriend(User friend_to_add){
    this->_userList.add(friend_to_add);
 }

 std::string Profile::getPage() const{
    std::string userString;
    userString = "Status: " + this->_page.getStatus() + "\n";
    userString = userString + "*******************\n*******************\n";
    userString = userString + this->_page.getPosts();

    return userString;

 }

 std::string Profile::getFriends() const {
    std::string userFriends = "";

    UserNode* current = this->_userList.get_first();

    if(current == nullptr) {
        return userFriends;
    }
    while(current != nullptr){
        userFriends = userFriends + current->get_data().getUserName() + ",";
        current = current->get_next();
    }
        userFriends.pop_back(); // remove last comma
        return userFriends;
 }

std::string Profile::getFriendsWithSameNameLength() const {
    std::string userFriendsWithSameLength = "";
    
    size_t length = (this->_user.getUserName()).length();  // calculates length of userName

    UserNode* current = this->_userList.get_first();

    if(current == nullptr) {
        return userFriendsWithSameLength;
    }

    while(current != nullptr){
        if((current->get_data().getUserName()).length() == length) {
        userFriendsWithSameLength = userFriendsWithSameLength + current->get_data().getUserName() + ",";
        }
        current = current->get_next();
    }
        if (!userFriendsWithSameLength.empty()) {
            userFriendsWithSameLength.pop_back(); // remove last comma if string is not empty
        }

        return userFriendsWithSameLength;
}

// not implemented method
void Profile::changeAllWordsInStatus(std::string word){
    std::cout << "changeAllWordsInStatus method implementation is needed to run bonus" << std::endl;
    return;
}

// not implemented method
void Profile::changeWordInStatus(std::string word_to_replace, std::string new_word){
    std::cout << "changeWordsInStatus method implementation is needed to run bonus" << std::endl;
    return;
}