#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "User.h"
#include "UsersData.h"

//****** This file contains 4 functions; "getUsersFromXml" is the main and you can take the output vector from it ******//



string extractFromTag (const string & line , const string &tag);


User userAnalyze (ifstream& file );
Post analyzePost(ifstream& file);


using namespace std;


string extractFromTag (const string & line , const string &tag){
size_t start = line.find("<" + tag + ">" )  ;
size_t end = line.find ("</" + tag + ">" );
if (start != string::npos && end!= string::npos ){

    start += tag.size()+2 ;
    return line.substr(start , end-start);
}
return "";
}




User userAnalyze (ifstream& file ){
string line ;

User user ;
user.setId(0);

while(getline(file ,line) ){
        if (line.find("</user>") != string::npos){
            break;
        }

        if(line.find("<name>") != string::npos){
         user.setName ( extractFromTag(line , "name") );
        }
        if (line.find("<id>")  != string::npos ){
            user.setId ( stoi(extractFromTag(line , "id") ) );
        }

        if(line.find("<follower>") != string::npos ){ ///list of followers detected

           string followerId ;

           while (getline(file, line) ){
                if(line.find("<id>") != string::npos){

                    followerId = extractFromTag(line , "id");
                }
                 if (!followerId.empty()){
                    int idStringToInt = stoi(followerId);;
                 /*
                    follower.setId(stoi(followerId)) ;
                    user.pushFollower(follower) ;*/
                    bool repeatedId = false ;
                    for(int i=0 ; i < (int)user.getFollowers().size() ; i++){
                        if (user.getFollowers()[i].getID() == idStringToInt)
                         {
                             repeatedId = true ;
                             break;
                         }
                    }
                    if(!repeatedId){
                            User follower ;
                        follower.setId(idStringToInt);
                        user.pushFollower(follower) ;
                    }

           }
           if(line.find("</follower>") != string::npos )
                break;
           }

        }
        if(line.find("<post>") != string::npos){
         user.pushPost( analyzePost(file)  );
        }

}


return user ;
}


Post analyzePost(ifstream& file){

    string line ;
    string postBody = "";
    string topic = "";
    bool inBody =false;

            while (getline(file , line) ){

                if (line.find("</post>") != string::npos ){ ///end of followers list
                return Post{topic ,postBody} ;
            }

            if (line.find("<topic>") != string::npos){
                topic = extractFromTag(line, "topic");

            }
            if ( !inBody && line.find("<body>") != string::npos){
                    ///start accumulating the body in a string
                     inBody = true ;
                    size_t start = line.find("<body>")+6;
                    size_t end = line.find("</body>");
            if (end != string::npos){
                postBody += line.substr(start,end-start ) ;
                inBody = false;
            }else {
                postBody += line.substr(start ) ;
            }


               // body = extractFromTag(line, "body");

            }else if(inBody){
            size_t end  = line.find("</body>") ;
            if(end != string::npos ){

                postBody+= line.substr(0,end);
                inBody =false ;
            }else {

            postBody+= line  ;
            }

            }
     }
return Post{topic ,postBody} ;
}

//////////////////////////////////////////////////////////////Main Function
void UsersData::getUsersFromXml  (const string& filePath){

ifstream file (filePath ) ;
if(! file.is_open()){
    cout<<"error opening the file" ;
    return ;
    }

    string line ;
    while (getline(file , line)) {

        if(line.find("<user>") != string::npos ) ///if a user is detected
             {
            this->users.push_back(userAnalyze(file));
        }


    }
    file.close();
    return  ;

}







