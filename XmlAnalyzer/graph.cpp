#include "User.h"
#include "UsersData.h"
#include <vector>

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
}
