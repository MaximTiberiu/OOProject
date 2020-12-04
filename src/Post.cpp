#include "../include/Post.h"
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

Post::Post() = default;

Post::Post(const std::string& userID, const std::string& channelID) {
    this->userID = userID;
    this->channelID = channelID;
    setPostID();
    setPostDataFile();
}

Post::Post(const Post& p) {
    postID = p.postID;
    userID = p.userID;
    channelID = p.channelID;
    likes = p.likes;
    dislikes = p.dislikes;
    comms = p.comms;
    postDataFile = p.postDataFile;
}

Post::~Post() = default;

void Post::setPostID() {
    std::string id = "PO_";
    std::string userUPP = userID;
    std::transform(userUPP.begin(), userUPP.end(),userUPP.begin(), ::toupper);
    id += userUPP;
    id += "_";

    int r;
    srand((int)time(nullptr));
    r = (rand() % 100) + 1;
    r *= userID.length();
    id += std::to_string(r);

    postID = id;
}

void Post::setPostDataFile() {
    std::string path = "./channels/";
    path += channelID;
    path += "/";
    path += postID;
    path += ".txt";

    postDataFile = path;
}

std::string Post::getPostID() {
    return this->postID;
}