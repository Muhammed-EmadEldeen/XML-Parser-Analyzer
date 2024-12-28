#include <iostream>
#include "UsersData.cpp"
using namespace std;

User UsersData::getMostFollowingUser() {
    User* mostFollowingUser = nullptr;
    int maxFollowing = 0;

    for (auto& user : users) {
        int followingCount = 0;
        for (const auto& potentialFollowing : users) {
            if (find(potentialFollowing.getFollowers().begin(), potentialFollowing.getFollowers().end(), user) != potentialFollowing.getFollowers().end()) {
                ++followingCount;
            }
        }
        if (followingCount > maxFollowing) {
            maxFollowing = followingCount;
            mostFollowingUser = &user;
        }
    }

    return *mostFollowingUser;
}