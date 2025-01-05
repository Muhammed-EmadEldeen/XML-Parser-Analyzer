// #ifndef USERSDATA_H
// #define USERSDATA_H
// #include "User.h"
// #include <string>

// class UsersData {
// private:


// public:
//   vector<User> users;


//   /*string filePath;*/
//   //void parseXmlFile(string filename);
//   User getMostFollowedUser();
//   User getMostFollowingUser();
//   vector<string> findMutualFollowers(vector<string> userIds);
//   //vector<User> mutualFollowers(User user1, User user2);
//   vector<Post> getPostsByWord(string word);
//   vector<Post> getPostsByTopic(string topic);
//   vector<vector<int>> getFollowersMatrix();
//   //****Get the user vector functions****//
//   void getUsersFromXml (const string& filePath);

//   };

// #endif

// //




#ifndef USERSDATA_H
#define USERSDATA_H
#include "User.h"

using namespace std;

class UsersData {

public:
    vector<User> users;

<<<<<<< HEAD
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
=======
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
>>>>>>> 9f6a4a4974f8548a8d2ed61e20078b248d6b3b88
};

#endif
