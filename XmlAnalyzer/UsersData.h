
#ifndef USERSDATA_H
#define USERSDATA_H
#include "User.h"

using namespace std;

class UsersData {
 
public:
vector<User> users;


#ifndef USERSDATA_H
#define USERSDATA_H
#include "User.h"

class UsersData {
private:
  vector<User> users;

public:

  void parseXmlFile(string filename);
  User getMostFollowedUser();
  User getMostFollowingUser();
  vector<User> mutualFollowers(User user1, User user2);
  vector<Post> getPostsByWord(string word);
  vector<Post> getPostsByTopic(string topic);
  vector<vector<int>> getFollowersMatrix();

  //****Get the user vector functions****//
  vector <User> getUsersFromXml  (string filePath);
  string extractFromTag (const string & line , const string &tag);
  User userAnalyze (ifstream& file );
  Post analyzePost(ifstream& file);
  //************************************************//


};

#endif
