#include "UsersData.h"
#include <map>
using namespace std;

User UsersData::getMostFollowingUser() {
  User *mostFollowingUser = nullptr;
  map<int, int> followersCount;
  int maxFollowing = 0;
  for (auto &user : users) {
    for (auto &follower : user.getFollowers()) {
      followersCount[follower.getID()]++;
    }
  }
  for (auto &user : users) {
    int followingCount = followersCount[user.getID()];
    if (followingCount > maxFollowing) {
      maxFollowing = followingCount;
      mostFollowingUser = &user;
    }
  }
  return *mostFollowingUser;
}
