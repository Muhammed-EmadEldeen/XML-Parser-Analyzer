#include "User.cpp"

using namespace std;

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
  vector <User> getUsersFromXml  (const string& filePath);
  string extractFromTag (const string & line , const string &tag);
  User userAnalyze (ifstream& file );
  Post analyzePost(ifstream& file);
  //************************************************//

};
