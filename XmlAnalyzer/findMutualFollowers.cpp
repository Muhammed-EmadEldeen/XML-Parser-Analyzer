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
    vector<string> findMutualFollowers(vector<string> userIds) {
    if (userIds.empty()) {
        return vector<string>();
    }

    // Vector to store mutual followers
    vector<string> mutualFollowers;

    // Get the followers of the first user
    vector<string> firstUserFollowers = users[userIds[0]].getFollowerIDs();

    // Check each follower of the first user to see if they follow all other users
    for (const string& followerId : firstUserFollowers) {
        bool isMutual = true;
        for (size_t i = 1; i < userIds.size(); ++i) {
            vector<string> currentUserFollowers = users[userIds[i]].getFollowerIDs();
            if (find(currentUserFollowers.begin(), currentUserFollowers.end(), followerId) == currentUserFollowers.end()) {
                isMutual = false;
                break;
            }
        }
        if (isMutual) {
            mutualFollowers.push_back(followerId);
        }
    }

    return mutualFollowers;
}
