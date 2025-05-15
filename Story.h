
#ifndef STORY_H
#define STORY_H

#include <string>
#include <ctime>
using namespace std;

class Story {
private:
    string userID;
    time_t publishedTime;
    string storyText;
    string storyPhotoPath;

public:
    Story(const string& uid, const string& text, const string& photo = "");

    string getUserID() const;
    time_t getPublishedTime() const;
    string getStoryText() const;
    string getStoryPhotoPath() const;

    bool isExpired() const;

    string serialize() const;
    static Story deserialize(const string& data);
};


