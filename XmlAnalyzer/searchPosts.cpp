#include <iostream>
#include <vector>
#include <string>
// #include "UsersVector.h"
#include "UsersData.h"

using namespace std;

vector<Post> UsersData::getPostsByTopic(string searchTopic) {
    vector<Post> matchingPosts;
    User* usersposts = nullptr;
    for (auto& user : users) {
        for (Post& post : user.getPosts()) {
            if (post.topic == searchTopic) {
                matchingPosts.push_back(post);
            }
        }
    }
    
    return matchingPosts;
}

int main() {
   // Sample data
    // vector<User> users = {
    //     {1, "Alice", {{"Tech", "C++ is great!"}, {"Travel", "I visited Japan."}}},
    //     {2, "Bob", {{"Tech", "AI is the future."}, {"Food", "I love pizza."}}},
    //     {3, "Charlie", {{"Health", "Exercise daily."}, {"Tech", "Learn Python."}}}
    // };
    // string Search_topic = "Topic 1";

    // vector<Post> results = getPostsByTopic(Search_topic);

    // for (const Post& post : results) {
    //     cout << post.topic << "  " << post.body << "\n";
    // }

    return 0;
}