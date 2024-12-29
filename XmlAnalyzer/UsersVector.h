#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


#include "UsersVector.cpp"

using namespace std;

//****** This file contains 4 functions; "getUsersFromXml" is the main and you can take the output vector from it ******//



vector <User> getUsersFromXml  (const string& filePath);
string extractFromTag (const string & line , const string &tag);
User userAnalyze (ifstream& file );
Post analyzePost(ifstream& file);