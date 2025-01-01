#ifndef USERSDATA_H
#define USERSDATA_H
#include "User.h"
#include <string>

class UsersData {
private:


public:
  vector<User> users;


  /*string filePath;*/
  //void parseXmlFile(string filename);
  User getMostFollowedUser();
  User getMostFollowingUser();
  vector<string> findMutualFollowers(vector<string> userIds);
  //vector<User> mutualFollowers(User user1, User user2);
  vector<Post> getPostsByWord(string word);
  vector<Post> getPostsByTopic(string topic);
  vector<vector<int>> getFollowersMatrix();
  //****Get the user vector functions****//
  void getUsersFromXml (const string& filePath);

  };

#endif

//




