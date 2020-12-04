// include
#include "../include/User.h"
#include "../rlutil/rlutil.h"
#include <thread>

#ifdef GH_ACTIONS
#define waitkey (void)
#else
#define waitkey rlutil::anykey("Press any key to continue...\n")
#endif

#define setRed rlutil::setColor(rlutil::RED)
#define setYellow rlutil::setColor(rlutil::YELLOW)
#define setCyan rlutil::setColor(rlutil::CYAN)
#define setGreen rlutil::setColor(rlutil::GREEN)
#define clear rlutil::cls()

User::User() = default;

User::User(const std::string& username, const std::string& password, const std::string& email)
            : Participant(username, password, email) {
    setGrade();
}

User::User(const User& us)
            : Participant(us) {
    channels = us.channels;
    posts = us.posts;
    likes = us.likes;
    dislikes = us.dislikes;
    comms = us.comms;
}

User::~User() = default;

void User::setGrade() {
    if(posts.size() <= 1) {
        grade = firstTimer;
        return;
    }
    if(posts.size() > 1) {
        if(likes.size() - dislikes.size() >= 20) {
            if(comms.size() >= 20)
                grade = addict;
            else
                grade = activist;
        } else
            grade = regularJoe;
        return;
    }
    if(posts.size() >= 100 && comms.size() >= 100 && (likes.size() - dislikes.size()) >= 100)
        grade = master;
}

std::unique_ptr<Participant> User::clone() {
    return std::make_unique<User>(*this);
}

void User::showUserOptions() {
    setYellow;
    std::cout << "Please select an option from the menu below: \n";
    setGreen;
    std::cout << "POSTS\n";
    setYellow;
    std::cout << "\t1. Create a new post\n";
    std::cout << "\t2. Manage my posts\n";
    std::cout << "\t3. Show all posts\n";
    setGreen;
    std::cout << "CHANNELS\n";
    setYellow;
    std::cout << "\t4. Create a new channel\n";
    std::cout << "\t5. Subscribe to a channel\n";
    std::cout << "\t6. Unsubscribe from a channel\n";
    std::cout << "\t7. Go to a channel\n";
    setGreen;
    std::cout << "PROFILE\n";
    setYellow;
    std::cout << "\t8. Sign out\n";
    std::cout << "\t9. My profile\n\n";
}

void User::userPanel() {
    clear;
    std::cout << "-------------------------------------------------\n";
    setYellow;
    std::cout << "                    Welcome, " << getUsername() <<"!\n";
    setGreen;
    std::cout << "-------------------------------------------------\n\n";

    showUserOptions();
    std::cout << "Please select your choice: ";
    setCyan;
    unsigned short option;
    std::cin >> option;

    switch(option) {
        case 1: {
            // Create a new post
            return;
        }
        case 2: {
            // Manage my posts
            return;
        }
        case 3: {
            // Show all posts
            return;
        }
        case 4: {
            // Create a new channel
            return;
        }
        case 5: {
            // Subscribe to a channel
            return;
        }
        case 6: {
            // Unsubscribe from a channel
            return;
        }
        case 7: {
            // Go to a channel
            return;
        }
        case 8: {
            // Sign out
            return;
        }
        case 9: {
            // My profile
            return;
        }
        default: {
            setRed;
            std::cout << "Incorrect option!\n";

            std::this_thread::sleep_for(std::chrono::seconds(2));
            userPanel();
            return;
        }
    }

}

std::ostream &operator<< (std::ostream &out, const User& u) {
    // print the channels' IDs the user has subscribed to
    out << u.channels.size() << "\n";
    for(const auto & channel : u.channels)
        out << channel << " ";

    // print user's posts' IDs
    out << "\n" << u.posts.size() << "\n";
    for(const auto & post : u.posts)
        out << post << " ";

    // print others users' IDs that likes user's posts
    out << "\n" << u.likes.size() << "\n";
    for(const auto & like : u.likes)
        out << like << " ";

    // print others users' IDs that dislikes user's posts
    out << "\n" << u.dislikes.size() << "\n";
    for(const auto & dislike : u.dislikes)
        out << dislike << " ";

    // print comments' IDs the user has written
    out << "\n" << u.comms.size() << "\n";
    for(const auto & comm : u.comms)
        out << comm << " ";

    return out;
}
