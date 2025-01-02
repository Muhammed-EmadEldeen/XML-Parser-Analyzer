#include "UsersData.h"
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> UsersData::suggestFollow(int id) {
  User *current = findUserById(id);
  unordered_set<int> followerSeen;
  followerSeen.insert(id);
  vector<int> ans;
  for (User u : current->getFollowers()) {
    followerSeen.insert(u.getID());
  }

  for (User u : current->getFollowers()) {
    User *temp = findUserById(u.getID());
    for (User s : temp->getFollowers()) {
      if (followerSeen.find(s.getID()) == followerSeen.end()) {
        followerSeen.insert(s.getID());
        ans.push_back(s.getID());
      }
    }
  }
  return ans;
}
