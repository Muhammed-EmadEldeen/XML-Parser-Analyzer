#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "UsersData.h"
// #include "UsersVector.cpp"

using namespace std;

vector<Post> UsersData::getPostsByWord(string searchWord) {
    vector<Post> matchingPosts;
    User* usersposts = nullptr;
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
   
    
//     vector<Post> wordResults = getPostsByWord(Search_word);
//     for (Post& post : wordResults) {
//         std::cout << "Topic: " << post.topic << ", Body: " << post.body << "\n";
//     }
// }

