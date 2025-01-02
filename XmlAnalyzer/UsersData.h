
#ifndef USERSDATA_H
#define USERSDATA_H
#include "User.h"

using namespace std;

class UsersData {

public:
  vector<User> users;

  User getMostFollowedUser();
  User getMostFollowingUser();
  vector<Post> getPostsByWord(string word);
  vector<Post> getPostsByTopic(string topic);
  vector<vector<int>> getFollowersMatrix();
  string extractFromTag(const string &line, const string &tag);
  User userAnalyze(ifstream &file);
  Post analyzePost(ifstream &file);
  vector<string> findMutualFollowers(vector<string> userIds);
  vector<int> suggestFollow(int id);
  void getUsersFromXml(const string &filePath);

  User *findUserById(int id);
};

#endif
