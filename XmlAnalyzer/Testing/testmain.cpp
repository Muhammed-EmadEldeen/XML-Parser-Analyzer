#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <fstream>

using namespace std;

class User {
public:
    string userId;
    string name;
    unordered_set<string> following;

    User() = default;
    User(string userId, string name) : userId(move(userId)), name(move(name)) {}
};

class SocialNetwork {
public:
    unordered_map<string, User> users;

    void addUser(const string& userId, const string& name) {
        if (users.find(userId) == users.end()) {
            users.emplace(userId, User(userId, name));
        }
    }

    void addFollowing(const string& followerId, const string& followingId) {
        if (users.find(followerId) != users.end() && users.find(followingId) != users.end()) {
            users[followerId].following.insert(followingId);
        }
    }

    User* getMostFollowingUser() {
        size_t maxFollowing = 0;
        User* activeUser = nullptr;
        for (auto& pair : users) {
            if (pair.second.following.size() > maxFollowing) {
                maxFollowing = pair.second.following.size();
                activeUser = &pair.second;
            }
        }
        return activeUser;
    }
};

SocialNetwork parseXML(const string& filePath) {
    SocialNetwork network;
    ifstream file(filePath);
    stringstream buffer;
    buffer << file.rdbuf();
    string xmlContent = buffer.str();

    size_t pos = 0;
    while ((pos = xmlContent.find("<node id=", pos)) != string::npos) {
        size_t start = xmlContent.find("\"", pos) + 1;
        size_t end = xmlContent.find("\"", start);
        string nodeId = xmlContent.substr(start, end - start);

        start = xmlContent.find("<data key=\"label\">", end) + 18; // Adjusted position
        end = xmlContent.find("</data>", start);
        string name = xmlContent.substr(start, end - start);

        network.addUser(nodeId, name);
        pos = end;
    }

    pos = 0;
    while ((pos = xmlContent.find("<edge ", pos)) != string::npos) {
        size_t sourceStart = xmlContent.find("source=\"", pos) + 8;
        size_t sourceEnd = xmlContent.find("\"", sourceStart);
        string sourceId = xmlContent.substr(sourceStart, sourceEnd - sourceStart);

        size_t targetStart = xmlContent.find("target=\"", pos) + 8;
        size_t targetEnd = xmlContent.find("\"", targetStart);
        string targetId = xmlContent.substr(targetStart, targetEnd - targetStart);

        network.addFollowing(sourceId, targetId);
        pos = targetEnd;
    }

    return network;
}

int main() {
    string filePath = "test.graphml";
    SocialNetwork network = parseXML(filePath);
    User* mostActive = network.getMostFollowingUser();
    if (mostActive) {
        cout << "The user following the most users: " << mostActive->name
             << " (ID: " << mostActive->userId << ") with " << mostActive->following.size() << " followings." << endl;
    } else {
        cout << "No users found." << endl;
    }
    return 0;
}





