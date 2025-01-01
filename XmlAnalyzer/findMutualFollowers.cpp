#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>  
#include "User.h"
#include "UsersData.h"
using namespace std;
    vector<string> UsersData::findMutualFollowers(vector<string> userIds) {
        if (userIds.empty()) {
            return vector<string>();
        }       
        // Count how many times each follower appears
        map<string, int> followerCount;        
        // For each user in our input list
        for (string userId : userIds) {
            // Get their followers
            if (users.find(userId) != users.end()) {
                for (string followerId : users[userId].followers) {
                    followerCount[followerId]++;
                }
            }
        }      
        // Find followers who follow all users in our input list
        vector<string> mutualFollowers;
        for (auto const& pair : followerCount) {
            // If follower count equals number of input users, they follow all users
            if (pair.second == userIds.size()) {
                mutualFollowers.push_back(pair.first);
            }
        }   
        return mutualFollowers;
    }
