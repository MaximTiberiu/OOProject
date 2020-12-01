#pragma once

// include
#include <vector>
#include <memory>

class Post {
private:
    unsigned int postID;
    unsigned int userID;
    unsigned int channelID;
    std::vector<unsigned int> likes;
    std::vector<unsigned int> dislikes;

    std::vector<std::unique_ptr<Post>> comms;
public:
    Post();
    Post(const std::unique_ptr<Post>&);
    ~Post();
};