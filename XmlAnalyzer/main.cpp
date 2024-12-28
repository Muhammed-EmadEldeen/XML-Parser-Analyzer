#include <iostream>
#include "UsersVector.h"

using namespace std;

///used to see the result of users vector
void displayUsers( vector<User> &users) {
    for ( User &user : users) {
        cout << "Name: " << user.getName() << endl;
        cout << "ID: " << user.getID() << endl;
        cout << "Followers: ";
        for ( User &follower : user.getFollowers()) {
            cout << follower.getName() << " (ID: " << follower.getID() << ") ";
        }
        cout << endl;

        cout << "Posts: " << endl;
        for ( Post &post : user.getPosts()) {
            cout << "  Topic: " << post.topic << endl;
            cout << "  Body: " << post.body << endl;
        }

        cout << endl;
    }
}



int main(int argc, char *argv[]) {
  try {
        string filePath = "C:/Desktop/test.xml";  /// put your test file path with forward slashes /
        vector<User> users = getUsersFromXml(filePath);
        displayUsers(users);
      } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return -1;
    }

    return 0;
}

