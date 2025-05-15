#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Story.h" 
using namespace std;

class User {
private:
    string userID;
    string mobileNumber;
    string password;
    string firstName;
    string lastName;
    vector<string> contacts;
    vector<string> chatRooms;
    vector<Story> stories; 
    string profilePhoto;
    string about;
    bool profileVisibleToAll;

public:
    User() = default;
    User(const string& uid, const string& mobile, const string& pwd,
         const string& fname, const string& lname);

  
    string getID() const;
    string getMobileNumber() const;
    string getPassword() const;
    string getFirstName() const;
    string getLastName() const;
    const vector<string>& getContacts() const;
    const vector<string>& getChatRooms() const;
    vector<Story> getActiveStories() const; // جديد
    string getProfilePhoto() const;
    string getAbout() const;
    bool isProfileVisibleToAll() const;

   
    void setPassword(const string& pwd);
    void setProfileInfo(const string& photo, const string& aboutDesc, bool visibility);

    
    void addContact(const string& contactID);
    void removeContact(const string& contactID);
    void addChatRoom(const string& chatRoomID);
    void removeChatRoom(const string& chatRoomID);


    void createStory(const string& text, const string& photoPath = ""); // جديد

   
    bool canViewProfile(const string& viewerID) const;

    
    string serialize() const;
    static User deserialize(const string& data);
};


