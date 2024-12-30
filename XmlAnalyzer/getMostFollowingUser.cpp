#include "UsersData.h"
#include <iostream>
using namespace std;
User UsersData::getMostFollowingUser() {
    User* mostFollowingUser = nullptr;
    int maxFollowing = 0;

    for (auto& user : users) {
        int followingCount = 0;

        for (auto& otherUser : users) {
            vector<User> followers = otherUser.getFollowers();
            for (auto& follower : followers) {
                if (follower.getID() == user.getID()) {
                    followingCount++;
                    break;
                }
            }
        }
        if (followingCount > maxFollowing) {
            maxFollowing = followingCount;
            mostFollowingUser = &user;
        }
    }
    return *mostFollowingUser;
}
