#pragma once

// include
#include <iostream>
#include <vector>
#include <memory>
#include "Post.h"

class Channel {
private:
    std::string channelID;
    std::string channelDataFile;
    std::string name;

    std::string user;
    std::string description;
    //std::vector<std::unique_ptr<Post>> posts;

    void setChannnelID();
    void setChannelDataFile();
    void createChannelDirectory();
public:
    Channel();
    Channel(const std::string&, const std::string&, const std::string&);
    Channel(const Channel&);
    ~Channel();

    friend std::ostream &operator<< (std::ostream&, const Channel&);
};

