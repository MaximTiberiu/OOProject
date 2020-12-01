#pragma once

// include
#include <iostream>
#include <vector>
#include <memory>
#include "Post.h"

class Channel {
private:
    unsigned int channelID;
    std::string name;
    std::string description;
    std::vector<std::unique_ptr<Post>> posts;
public:

};

