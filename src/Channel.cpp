#include "../include/Channel.h"
#include "../rlutil/rlutil.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <io.h>

#define setRed rlutil::setColor(rlutil::RED)

Channel::Channel() = default;

Channel::Channel(const std::string& name, const std::string& user, const std::string& description) {
    this->name = name;
    this->user = user;
    this->description =  description;
    setChannnelID();
    createChannelDirectory();
    setChannelDataFile();
}

Channel::Channel(const Channel &ch) {
    channelID = ch.channelID;
    name = ch.name;
    user = ch.user;
    description = ch.description;
    posts = ch.posts;
}

Channel::~Channel() = default;

void Channel::setChannnelID() {
    std::string id = "CH_";
    std::string userUPP = user;
    std::transform(userUPP.begin(), userUPP.end(),userUPP.begin(), ::toupper);
    id += userUPP;
    id += "_";

    int r;
    srand((int)time(nullptr));
    r = (rand() % 100) + 1;
    r *= user.length();
    id += std::to_string(r);

    channelID = id;
}

void Channel::setChannelDataFile() {
    std::string path = "./channels/";
    path += channelID;
    path += "/";
    path += channelID;
    path += ".txt";
    channelDataFile = path;
}

void Channel::createChannelDirectory() {
    std::string path = "./channels/";
    path += channelID;

    if(mkdir(path.c_str())) {
        setRed;
        throw std::runtime_error("Could not create directory");
    }
}

std::ostream &operator<< (std::ostream& out, const Channel& ch) {
    out << ch.posts.size() << "\n";
    for(const auto & post : ch.posts)
        out << post->getPostID() << " ";
}
