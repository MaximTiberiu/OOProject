#include "../include/Post.h"

Post::Post() {

}

Post::Post(const std::unique_ptr<Post>& p) {
    postID = p->postID;
    userID = p->userID;
    channelID = p->channelID;
    likes = p->likes;
    dislikes = p->dislikes;
}

Post::~Post() = default;