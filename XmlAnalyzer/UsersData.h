#ifndef USERSDATA_H
#define USERSDATA_H
#include "User.h"

class UsersData {

public:

  vector<User> users;

  void parseXmlFile(string filename);
  User getMostFollowedUser();
  User getMostFollowingUser();
  vector<User> mutualFollowers(User user1, User user2);
  vector<Post> getPostsByWord(string word);
  vector<Post> getPostsByTopic(string topic);
  vector<vector<int>> getFollowersMatrix();
  vector<string> findMutualFollowers(vector<string> userIds);
  //****Get the user vector functions****//
  void getUsersFromXml (const string& filePath);
};

#endif
