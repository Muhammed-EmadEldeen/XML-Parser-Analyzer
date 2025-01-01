#include "UsersData.h"

using namespace std;

User UsersData::getMostFollowedUser() {
  User *mostFollowedUser = nullptr;
  int maxFollowers = 0;

  for (auto &user : users) {
    int followerCount = user.getFollowers().size();
    if (followerCount > maxFollowers) {
      maxFollowers = followerCount;
      mostFollowedUser = &user;
    }
  }

  return *mostFollowedUser;
}
