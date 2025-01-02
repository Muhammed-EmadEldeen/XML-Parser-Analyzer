#include "User.h"
#include "UsersData.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

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
