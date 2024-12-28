#include <string>
#include <vector>


using namespace std;

struct Post {
  string topic;
  string body;

};


class User {

protected:
  static int idCounter  ;

private:
  int id;
  string name;
  vector<User> followers;
  vector<Post> posts;


public:


  int getID() { return id; }

  void setName (string name){
  this->name = name ;}

  void setId  (int id ){
  this->id = id ;}

  void setFollowers(vector<User> followers){
  this-> followers = followers; }

  void pushFollower(User follower){
      this->followers.push_back( follower);
  }
  void pushPost(Post post){
      this->posts.push_back(post);
  }



  string getName() { return name; }

  int getId (){return id; }

  vector<User> getFollowers() { return followers; }

  vector<Post> getPosts() { return posts; }


  User (){};

  User(string name) {
    this->id = ++idCounter;
    this->name = name;
  }


  User(string name, vector<User> followers) {
    this->id = ++idCounter;
    this->name = name;
    this->followers = followers;
  }

  User(string name, vector<User> followers, vector<Post> posts) {
    this->id = ++idCounter;
    this->name = name;
    this->followers = followers;
    this->posts = posts;
  }
  User(int id, string name, vector<User> followers, vector<Post> posts) {
    this->id = id;
    this->name = name;
    this->followers = followers;
    this->posts = posts;
  }

  void followed_by(User user) { followers.push_back(user); }

  void post(string topic, string body) {
    Post post;
    post.topic = topic;
    post.body = body;
    posts.push_back(post);
  }




};

int User::idCounter = 0;
