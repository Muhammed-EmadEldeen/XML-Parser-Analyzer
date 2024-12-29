#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "UsersData.h"

using namespace std;

vector<Post> UsersData::getPostsByWord(string searchWord) {
    vector<Post> matchingPosts;
    string filePath = "test.xml";
    vector<User> users = getUsersFromXml(filePath);
    for (User& user : users) {
        for (Post& post : user.getPosts()) {
            if (post.body.find(searchWord) != string::npos || post.topic.find(searchWord) != string::npos) {
                matchingPosts.push_back(post);
            }
        }
    }
    
    return matchingPosts;
}

// int main()
// {  
//     string Search_word = "This";
//     UsersData user1;
    
//     vector<Post> wordResults = getPostsByWord(Search_word);
//     for (Post& post : wordResults) {
//         std::cout << "Topic: " << post.topic << ", Body: " << post.body << "\n";
//     }
// }

