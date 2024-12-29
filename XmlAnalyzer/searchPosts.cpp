#include <iostream>
#include <vector>
#include <string>
#include "UsersVector.h"

using namespace std;

vector<Post> getPostsByTopic(string searchTopic) {
    vector<Post> matchingPosts;
    string filePath = "test.xml";
    vector<User> users = getUsersFromXml(filePath);
    for (const User& user : users) {
        for (const Post& post : user.posts) {
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
    string Search_topic = "Topic 1";
    // UsersData user2;

    vector<Post> results = getPostsByTopic(Search_topic);

    for (const Post& post : results) {
        cout << post.topic << "  " << post.body << "\n";
    }

    return 0;
}