#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <algorithm>  

using namespace std;

// Simple User class to store user information
class User {
public:
    string id;
    string name;
    vector<string> followers;  // List of user IDs who follow this user
    
    // Constructor
    User(string userId = "", string userName = "") {
        id = userId;
        name = userName;
    }
};

// Main class to handle the social network
class SocialNetwork {
private:
    map<string, User> users;  // Map to store users with their IDs as keys

public:
    // Add a new user to the network
    void addUser(string id, string name) {
        users[id] = User(id, name);
    }
    
    // Add a follower to a user
    void addFollower(string userId, string followerId) {
        if (users.find(userId) != users.end()) {
            users[userId].followers.push_back(followerId);
        }
    }
    
    // Find mutual followers among a group of users
    vector<string> findMutualFollowers(vector<string> userIds) {
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
    
    // Get user name by ID
    string getUserName(string id) {
        if (users.find(id) != users.end()) {
            return users[id].name;
        }
        return "Unknown User";
    }
};

// Function to parse XML and create the social network
SocialNetwork loadFromXML(string filename) {
    SocialNetwork network;
    ifstream file(filename);
    string line;
    
    string currentId = "";
    string currentName = "";
    
    while (getline(file, line)) {
        // Remove whitespace
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
        
        // Parse user ID
        if (line.find("<id>") != string::npos) {
            currentId = line.substr(4, line.find("</id>") - 4);
        }
        // Parse user name
        else if (line.find("<name>") != string::npos) {
            currentName = line.substr(6, line.find("</name>") - 6);
            network.addUser(currentId, currentName);
        }
        // Parse follower
        else if (line.find("<follower>") != string::npos) {
            getline(file, line);  // Get follower ID line
            line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
            string followerId = line.substr(4, line.find("</id>") - 4);
            network.addFollower(currentId, followerId);
        }
    }
    
    return network;
}

int main() {
    // Load the social network from XML file
    SocialNetwork network = loadFromXML("test.xml");
    
    // Find mutual followers for users 1, 2, and 3
    vector<string> usersToCheck = {"1", "2", "3"};
    vector<string> mutualFollowers = network.findMutualFollowers(usersToCheck);
    
    // Print results
    cout << "Mutual followers for users 1, 2, and 3:" << endl;
    for (string followerId : mutualFollowers) {
        cout << "ID: " << followerId << ", Name: " << network.getUserName(followerId) << endl;
    }
    
    return 0;
}