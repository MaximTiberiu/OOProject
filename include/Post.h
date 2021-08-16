#pragma once

// include
#include <vector>
#include <memory>

class Post {
private:
    std::string postID;
    std::string userID;
    std::string channelID;
    std::vector<std::string> likes;
    std::vector<std::string> dislikes;
    //std::vector<std::unique_ptr<Post>> comms;
    std::string postDataFile;

    void setPostID();
    void setPostDataFile();

public:
    Post();
    Post(const std::string&, const std::string&);
//    Post(const Post&);
    Post(const std::unique_ptr<Post>&);
    ~Post();

    // getters
    std::string getPostID();
};