#include "analyzerwindow.h"
#include "ui_analyzerwindow.h"
#include "User.h"
#include "UsersData.h"
#include "GraphVisualisation.h"

#include <QString>
#include <QStringList>
#include <QVector>
#include <string>
#include <vector>

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <QListWidget>

using namespace std;


// void AnalyzerWindow::displayVectorInListWidget(const vector<string>& vOut , QListWidget* listWidget)
// {

//     listWidget->clear() ;

//     for(const auto & item : vOut){
//         listWidget->addItem(QString::fromStdString(item)) ;
//     }
// }

void displayVectorInListWidget(const vector<string>& vec, QListWidget* listWidget)
{
    // Clear the current content of the list widget
    listWidget->clear();

    // Populate the list widget with the vector items
    for (const string& item : vec)
    {
        listWidget->addItem(QString::fromStdString(item));
    }
}

vector<string> parseNumbers(const string& input)
{
    vector<string> result;
    stringstream ss(input);
    string token;

    // Split the input string by commas
    while (getline(ss, token, ','))
    {
        // Trim leading and trailing spaces from the token
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);

        if (!token.empty()) // Ignore empty tokens
        {
            result.push_back(token);
        }
    }

    return result;
}

string filePath;
UsersData UsersDataOne;
User MostFollowedUser;
User MostFollowingUser;

AnalyzerWindow::AnalyzerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AnalyzerWindow)
{
    ui->setupUi(this);
}

AnalyzerWindow::~AnalyzerWindow()
{
    delete ui;
}

void AnalyzerWindow::on_dirBtn_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Directory"));
    filePath =dir.toStdString();
    ui->pathLabel->setText(dir);
}



void AnalyzerWindow::on_getMostFollowedUserBtn_clicked()
{
    MostFollowedUser= UsersDataOne.getMostFollowedUser();
    ui->getMostFollowedUserLbl->setText(QString::fromStdString(MostFollowedUser.getName()));
}


void AnalyzerWindow::on_getMostFollowingUserBtn_clicked()
{
    MostFollowingUser= UsersDataOne.getMostFollowingUser();
    ui->getMostFollowingUserLbl->setText(QString::fromStdString(MostFollowingUser.getName()));
}


void AnalyzerWindow::on_parseXmlFileBtn_clicked() //youssef
{
    //UsersDataOne.parseXmlFile(filePath);
    UsersDataOne.getUsersFromXml(filePath);
    ui->parseXmlFileLbl->setText("Done");

}


void AnalyzerWindow::on_pushButton_clicked()
{
    GraphVisualisation myGraphVisualisation;
    myGraphVisualisation.setModal(true);
    myGraphVisualisation.exec();
}




void AnalyzerWindow::on_mutualFollowersBtn_clicked()
{
    QString InputMutualIds = ui->lineEdit->text();

    vector<string> v = parseNumbers(InputMutualIds.toStdString());
    vector<string> vOut = UsersDataOne.findMutualFollowers(v);
    displayVectorInListWidget(vOut,ui->listWidget);
}




void AnalyzerWindow::on_getPostsByWordBtn_clicked()
{
    QString wordInPost = ui->getPostsByWordLineEdit->text();
    vector<Post> posts = UsersDataOne.getPostsByWord(wordInPost.toStdString());
    vector<string> postsTopics;
    for (int i=0; i< posts.size(); i++)
    {
        postsTopics[i]=posts[i].topic;
    }

    displayVectorInListWidget(postsTopics,ui->getPostsByWordListWidget);
    //    vector<Post> UsersData::getPostsByWord(string word){}

}


void AnalyzerWindow::on_getPostsByTopicBtn_clicked()
{
    QString topicSearch = ui->getPostsByTopicLineEdit->text();
    vector<Post> posts = UsersDataOne.getPostsByTopic(topicSearch.toStdString());
    vector<string> postsBody;
    for (int i=0; i< posts.size(); i++)
    {
        postsBody[i]=posts[i].body.substr(0,10);
    }

    displayVectorInListWidget(postsBody,ui->getPostsByTopicListWidget);
    //vector<Post> UsersData::getPostsByTopic(string topic){}
}

//doneeeee

