#include "User.cpp"
#include "UsersVector.h"

using namespace std;

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

  //****Get the user vector functions****//
  void getUsersFromXml (const string& filePath);
  //************************************************//

};
