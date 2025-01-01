#ifndef USERSDATA_H
#define USERSDATA_H
#include "User.h"
#include <string>

class UsersData {
private:
  vector<User> users;


public:
  /*string filePath;*/
  void parseXmlFile(string filename);
  User getMostFollowedUser();
  User getMostFollowingUser();
  vector<User> mutualFollowers(User user1, User user2);
  vector<Post> getPostsByWord(string word);
  vector<Post> getPostsByTopic(string topic);
  vector<vector<int>> getFollowersMatrix();
};

#endif
