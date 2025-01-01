#include "UsersData.h"
#include <iostream>
using namespace std;

User UsersData::getMostFollowingUser() {
    User* mostFollowingUser = nullptr;
    int maxFollowing = 0;
    for(auto& user : users) {
    int followingCount = user.getFollowers().size();
        if (followingCount > maxFollowing) {
            maxFollowing = followingCount;
            mostFollowingUser = &user;
        }
    }
    return *mostFollowingUser;
}
