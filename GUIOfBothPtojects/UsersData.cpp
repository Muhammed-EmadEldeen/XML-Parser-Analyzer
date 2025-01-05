// #include "UsersData.h"
// #include <string>
// #include <vector>
// //usersVector.h

// #include "User.h"
// using namespace std;


//     /*string filePath;*/
//     //void UsersData::parseXmlFile(string filename){}
//     User UsersData::getMostFollowedUser(){}
//     User UsersData::getMostFollowingUser(){}
//     //vector<User> UsersData::mutualFollowers(User user1, User user2){}
//     vector<string> UsersData::findMutualFollowers(vector<string> userIds){}

//     vector<Post> UsersData::getPostsByWord(string word){}
//     vector<Post> UsersData::getPostsByTopic(string topic){}
//     vector<vector<int>> UsersData::getFollowersMatrix(){

//         vector<vector<int>> theFollowersVector;
//         vector<int> userOne={1,2,3,4};
//         vector<int> userTwo={2,1,3,4};
//         vector<int> userThree={3,1,4};
//         vector<int> userFour={4,3};

//         vector<int> user5={5,2,6,8};
//         vector<int> user6={6,1,5};
//         vector<int> user7={7,1,8};
//         vector<int> user8={8,1};

//         theFollowersVector.push_back(userOne);
//         theFollowersVector.push_back(userTwo);
//         theFollowersVector.push_back(userThree);
//         theFollowersVector.push_back(userFour);
//         theFollowersVector.push_back(user5);
//         theFollowersVector.push_back(user6);
//         theFollowersVector.push_back(user7);
//         theFollowersVector.push_back(user8);
//         return theFollowersVector;
//     }
//     //
//     void UsersData::getUsersFromXml (const string& filePath){}





//     //temp
//     //  string extractFromTag (const string & line , const string &tag);


//     // User userAnalyze (ifstream& file );
//     // Post analyzePost(ifstream& file);


//     // using namespace std;


//     // string extractFromTag (const string & line , const string &tag){
//     //     size_t start = line.find("<" + tag + ">" )  ;
//     //     size_t end = line.find ("</" + tag + ">" );
//     //     if (start != string::npos && end!= string::npos ){

//     //         start += tag.size()+2 ;
//     //         return line.substr(start , end-start);
//     //     }
//     //     return "";
//     // }




//     // User userAnalyze (ifstream& file ){
//     //     string line ;

//     //     User user ;
//     //     user.setId(0);

//     //     while(getline(file ,line) ){
//     //         if (line.find("</user>") != string::npos){
//     //             break;
//     //         }

//     //         if(line.find("<name>") != string::npos){
//     //             user.setName ( extractFromTag(line , "name") );
//     //         }
//     //         if (line.find("<id>")  != string::npos ){
//     //             user.setId ( stoi(extractFromTag(line , "id") ) );
//     //         }

//     //         if(line.find("<follower>") != string::npos ){ ///list of followers detected

//     //             string followerId ;

//     //             while (getline(file, line) ){
//     //                 if(line.find("<id>") != string::npos){

//     //                     followerId = extractFromTag(line , "id");
//     //                 }
//     //                 if (!followerId.empty()){
//     //                     int idStringToInt = stoi(followerId);;
//     //                     /*
//     //                 follower.setId(stoi(followerId)) ;
//     //                 user.pushFollower(follower) ;*/
//     //                     bool repeatedId = false ;
//     //                     for(int i=0 ; i < (int)user.getFollowers().size() ; i++){
//     //                         if (user.getFollowers()[i].getID() == idStringToInt)
//     //                         {
//     //                             repeatedId = true ;
//     //                             break;
//     //                         }
//     //                     }
//     //                     if(!repeatedId){
//     //                         User follower ;
//     //                         follower.setId(idStringToInt);
//     //                         user.pushFollower(follower) ;
//     //                     }

//     //                 }
//     //                 if(line.find("</follower>") != string::npos )
//     //                     break;
//     //             }

//     //         }
//     //         if(line.find("<post>") != string::npos){
//     //             user.pushPost( analyzePost(file)  );
//     //         }

//     //     }


//     //     return user ;
//     // }


//     // Post analyzePost(ifstream& file){

//     //     string line ;
//     //     string postBody = "";
//     //     string topic = "";
//     //     bool inBody =false;

//     //     while (getline(file , line) ){

//     //         if (line.find("</post>") != string::npos ){ ///end of followers list
//     //             return Post{topic ,postBody} ;
//     //         }

//     //         if (line.find("<topic>") != string::npos){
//     //             topic = extractFromTag(line, "topic");

//     //         }
//     //         if ( !inBody && line.find("<body>") != string::npos){
//     //             ///start accumulating the body in a string
//     //             inBody = true ;
//     //             size_t start = line.find("<body>")+6;
//     //             size_t end = line.find("</body>");
//     //             if (end != string::npos){
//     //                 postBody += line.substr(start,end-start ) ;
//     //                 inBody = false;
//     //             }else {
//     //                 postBody += line.substr(start ) ;
//     //             }


//     //             // body = extractFromTag(line, "body");

//     //         }else if(inBody){
//     //             size_t end  = line.find("</body>") ;
//     //             if(end != string::npos ){

//     //                 postBody+= line.substr(0,end);
//     //                 inBody =false ;
//     //             }else {

//     //                 postBody+= line  ;
//     //             }

//     //         }
//     //     }
//     //     return Post{topic ,postBody} ;
//     // }

//     // //////////////////////////////////////////////////////////////Main Function
//     // void UsersData::getUsersFromXml  (const string& filePath){

//     //     ifstream file (filePath ) ;
//     //     if(! file.is_open()){
//     //         cout<<"error opening the file" ;
//     //         return ;
//     //     }

//     //     string line ;
//     //     while (getline(file , line)) {

//     //         if(line.find("<user>") != string::npos ) ///if a user is detected
//     //         {
//     //             this->users.push_back(userAnalyze(file));
//     //         }


//     //     }
//     //     file.close();
//     //     return  ;

//     // }



#include "UsersData.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// usersVector.h

#include "User.h"
using namespace std;

/*string filePath;*/
// void UsersData::parseXmlFile(string filename){}

User UsersData::getMostFollowedUser() {
<<<<<<< HEAD
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
// vector<User> UsersData::mutualFollowers(User user1, User user2){}
User *UsersData::findUserById(int id) {
    for (User &u : users) {
        if (u.getID() == id) {
            return &u;
        }
    }
    return nullptr;
}

vector<string> UsersData::findMutualFollowers(vector<string> userIds) {
    map<int, int> followers;
    vector<string> answer;

    for (string id : userIds) {
        User *currentUser = findUserById(stoi(id));
        if (!currentUser) {
            cout << "Error wrong ID" << endl;
            return answer;
        }
        for (User f : currentUser->getFollowers()) {
            followers[f.getID()]++;
        }
    }
    for (pair<int, int> e : followers) {
        if (e.second == userIds.size()) {
            answer.push_back(to_string(e.first));
        }
    }
    return answer;
}

vector<Post> UsersData::getPostsByWord(string searchWord) {
    vector<Post> matchingPosts;
    User *usersearch = nullptr;
    for (User &user : users) {
        for (Post &post : user.getPosts()) {
            if (post.body.find(searchWord) != string::npos ||
                post.topic.find(searchWord) != string::npos) {
                matchingPosts.push_back(post);
            }
        }
    }

    return matchingPosts;
}

vector<Post> UsersData::getPostsByTopic(string searchTopic) {
    vector<Post> matchingPosts;
    // vector<User> usersposts = users;
    User *usersss = nullptr;
    for (User &user : users) {
        for (Post &post : user.getPosts()) {
            if (post.topic == searchTopic) {
                matchingPosts.push_back(post);
            }
        }
    }

    return matchingPosts;
}

vector<vector<int>> UsersData::getFollowersMatrix() {
    vector<vector<int>> graph;
    int users_num = this->users.size();

    for (int i = 0; i < users_num; i++) {
        vector<int> node;
        node.push_back(this->users[i].getID());
        vector<User> followers = this->users[i].getFollowers();
        int followers_num = followers.size();

        for (int j = 0; j < followers_num; j++) {
            node.push_back(followers[j].getID());
        }

        graph.push_back(node);
    }

    return graph;
=======
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
// vector<User> UsersData::mutualFollowers(User user1, User user2){}
User *UsersData::findUserById(int id) {
  for (User &u : users) {
    if (u.getID() == id) {
      return &u;
    }
  }
  return nullptr;
}

vector<string> UsersData::findMutualFollowers(vector<string> userIds) {
  map<int, int> followers;
  vector<string> answer;

  for (string id : userIds) {
    User *currentUser = findUserById(stoi(id));
    if (!currentUser) {
      cout << "Error wrong ID" << endl;
      return answer;
    }
    for (User f : currentUser->getFollowers()) {
      followers[f.getID()]++;
    }
  }
  for (pair<int, int> e : followers) {
    if (e.second == userIds.size()) {
      answer.push_back(to_string(e.first));
    }
  }
  return answer;
}

vector<Post> UsersData::getPostsByWord(string searchWord) {
  vector<Post> matchingPosts;
  User *usersearch = nullptr;
  for (User &user : users) {
    for (Post &post : user.getPosts()) {
      if (post.body.find(searchWord) != string::npos ||
          post.topic.find(searchWord) != string::npos) {
        matchingPosts.push_back(post);
      }
    }
  }

  return matchingPosts;
}

vector<Post> UsersData::getPostsByTopic(string searchTopic) {
  vector<Post> matchingPosts;
  // vector<User> usersposts = users;
  User *usersss = nullptr;
  for (User &user : users) {
    for (Post &post : user.getPosts()) {
      if (post.topic == searchTopic) {
        matchingPosts.push_back(post);
      }
    }
  }

  return matchingPosts;
}

vector<vector<int>> UsersData::getFollowersMatrix() {
  vector<vector<int>> graph;
  int users_num = this->users.size();

  for (int i = 0; i < users_num; i++) {
    vector<int> node;
    node.push_back(this->users[i].getID());
    vector<User> followers = this->users[i].getFollowers();
    int followers_num = followers.size();

    for (int j = 0; j < followers_num; j++) {
      node.push_back(followers[j].getID());
    }

    graph.push_back(node);
  }

  return graph;
>>>>>>> 9f6a4a4974f8548a8d2ed61e20078b248d6b3b88
}
//
User userAnalyze(ifstream &file);

using namespace std;

string UsersData::extractFromTag(const string &line, const string &tag) {
<<<<<<< HEAD
    size_t start = line.find("<" + tag + ">");
    size_t end = line.find("</" + tag + ">");
    if (start != string::npos && end != string::npos) {

        start += tag.size() + 2;
        return line.substr(start, end - start);
    }
    return "";
}

User UsersData::userAnalyze(ifstream &file) {
    string line;

    User user;
    user.setId(0);

    while (getline(file, line)) {
        if (line.find("</user>") != string::npos) {
            break;
        }

        if (line.find("<name>") != string::npos) {
            user.setName(extractFromTag(line, "name"));
        }
        if (line.find("<id>") != string::npos) {
            user.setId(stoi(extractFromTag(line, "id")));
        }

        if (line.find("<follower>") != string::npos) { /// list of followers
            /// detected

            string followerId;

            while (getline(file, line)) {
                if (line.find("<id>") != string::npos) {

                    followerId = extractFromTag(line, "id");
                }
                if (!followerId.empty()) {
                    int idStringToInt = stoi(followerId);
                    ;
                    /*
             follower.setId(stoi(followerId)) ;
             user.pushFollower(follower) ;*/
                    bool repeatedId = false;
                    for (int i = 0; i < (int)user.getFollowers().size(); i++) {
                        if (user.getFollowers()[i].getID() == idStringToInt) {
                            repeatedId = true;
                            break;
                        }
                    }
                    if (!repeatedId) {
                        User follower;
                        follower.setId(idStringToInt);
                        user.pushFollower(follower);
                    }
                }
                if (line.find("</follower>") != string::npos)
                    break;
            }
        }
        if (line.find("<post>") != string::npos) {
            user.pushPost(analyzePost(file));
        }
    }

    return user;
=======
  size_t start = line.find("<" + tag + ">");
  size_t end = line.find("</" + tag + ">");
  if (start != string::npos && end != string::npos) {

    start += tag.size() + 2;
    return line.substr(start, end - start);
  }
  return "";
}

User UsersData::userAnalyze(ifstream &file) {
  string line;

  User user;
  user.setId(0);

  while (getline(file, line)) {
    if (line.find("</user>") != string::npos) {
      break;
    }

    if (line.find("<name>") != string::npos) {
      user.setName(extractFromTag(line, "name"));
    }
    if (line.find("<id>") != string::npos) {
      user.setId(stoi(extractFromTag(line, "id")));
    }

    if (line.find("<follower>") != string::npos) { /// list of followers
                                                   /// detected

      string followerId;

      while (getline(file, line)) {
        if (line.find("<id>") != string::npos) {

          followerId = extractFromTag(line, "id");
        }
        if (!followerId.empty()) {
          int idStringToInt = stoi(followerId);
          ;
          /*
             follower.setId(stoi(followerId)) ;
             user.pushFollower(follower) ;*/
          bool repeatedId = false;
          for (int i = 0; i < (int)user.getFollowers().size(); i++) {
            if (user.getFollowers()[i].getID() == idStringToInt) {
              repeatedId = true;
              break;
            }
          }
          if (!repeatedId) {
            User follower;
            follower.setId(idStringToInt);
            user.pushFollower(follower);
          }
        }
        if (line.find("</follower>") != string::npos)
          break;
      }
    }
    if (line.find("<post>") != string::npos) {
      user.pushPost(analyzePost(file));
    }
  }

  return user;
>>>>>>> 9f6a4a4974f8548a8d2ed61e20078b248d6b3b88
}

Post UsersData::analyzePost(ifstream &file) {

<<<<<<< HEAD
    string line;
    string postBody = "";
    string topic = "";
    bool inBody = false;

    while (getline(file, line)) {

        if (line.find("</post>") != string::npos) { /// end of followers list
            return Post{topic, postBody};
        }

        if (line.find("<topic>") != string::npos) {
            topic = extractFromTag(line, "topic");
        }
        if (!inBody && line.find("<body>") != string::npos) {
            /// start accumulating the body in a string
            inBody = true;
            size_t start = line.find("<body>") + 6;
            size_t end = line.find("</body>");
            if (end != string::npos) {
                postBody += line.substr(start, end - start);
                inBody = false;
            } else {
                postBody += line.substr(start);
            }

            // body = extractFromTag(line, "body");

        } else if (inBody) {
            size_t end = line.find("</body>");
            if (end != string::npos) {

                postBody += line.substr(0, end);
                inBody = false;
            } else {

                postBody += line;
            }
        }
    }
    return Post{topic, postBody};
=======
  string line;
  string postBody = "";
  string topic = "";
  bool inBody = false;

  while (getline(file, line)) {

    if (line.find("</post>") != string::npos) { /// end of followers list
      return Post{topic, postBody};
    }

    if (line.find("<topic>") != string::npos) {
      topic = extractFromTag(line, "topic");
    }
    if (!inBody && line.find("<body>") != string::npos) {
      /// start accumulating the body in a string
      inBody = true;
      size_t start = line.find("<body>") + 6;
      size_t end = line.find("</body>");
      if (end != string::npos) {
        postBody += line.substr(start, end - start);
        inBody = false;
      } else {
        postBody += line.substr(start);
      }

      // body = extractFromTag(line, "body");

    } else if (inBody) {
      size_t end = line.find("</body>");
      if (end != string::npos) {

        postBody += line.substr(0, end);
        inBody = false;
      } else {

        postBody += line;
      }
    }
  }
  return Post{topic, postBody};
>>>>>>> 9f6a4a4974f8548a8d2ed61e20078b248d6b3b88
}

//////////////////////////////////////////////////////////////Main Function
void UsersData::getUsersFromXml(const string &filePath) {

<<<<<<< HEAD
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "error opening the file";
        return;
    }

    string line;
    while (getline(file, line)) {

        if (line.find("<user>") != string::npos) /// if a user is detected
        {
            this->users.push_back(userAnalyze(file));
        }
    }
    file.close();
    return;
=======
  ifstream file(filePath);
  if (!file.is_open()) {
    cout << "error opening the file";
    return;
  }

  string line;
  while (getline(file, line)) {

    if (line.find("<user>") != string::npos) /// if a user is detected
    {
      this->users.push_back(userAnalyze(file));
    }
  }
  file.close();
  return;
>>>>>>> 9f6a4a4974f8548a8d2ed61e20078b248d6b3b88
}
