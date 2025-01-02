#include "analyzerwindow.h"
#include "ui_analyzerwindow.h"
#include "User.h"
#include "UsersData.h"
//#include "GraphVisualisation.h"

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
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>

//
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include <vector>
#include <cmath>
#include "analyzerwindow.h"

using namespace std;




void AnalyzerWindow::displayVectorInListWidget(const vector<string>& vec, QListWidget* listWidget)
{

    if (!listWidget) {
        qWarning() << "listWidget is null!";
        return;
    }

    listWidget->clear();

    for (const auto& item : vec) {
        listWidget->addItem(QString::fromStdString(item));
        qDebug() << "The value is:" << item ;
    }
}





vector<string> parseNumbers(string input) {
    stringstream ss(input);
    vector<string> output;
    string word;
    while (!ss.eof()) {
        getline(ss, word, ',');
        output.push_back(word);
    }
    return output;
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
    QString dir = QFileDialog::getOpenFileName(this, tr("Open File"));
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


void AnalyzerWindow::on_parseXmlFileBtn_clicked()
{
    //UsersDataOne.parseXmlFile(filePath);
    UsersDataOne.getUsersFromXml(filePath);
    ui->parseXmlFileLbl->setText("Done");

}


// void AnalyzerWindow::on_pushButton_clicked()
// {
//     GraphVisualisation myGraphVisualisation;
//     myGraphVisualisation.setModal(true);
//     myGraphVisualisation.exec();
// }




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
    vector<string> postsTopics(posts.size());
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
    vector<string> postsBody(posts.size());
    for (int i=0; i< posts.size(); i++)
    {
        postsBody[i]=posts[i].body;
    }

    displayVectorInListWidget(postsBody,ui->getPostsByTopicListWidget);
    //vector<Post> UsersData::getPostsByTopic(string topic){}
}





using namespace std;

//void GraphVisualisation::on_pushButton_clicked()
void AnalyzerWindow::on_pushButton_clicked()
{
    vector<vector<int>> theFollowersVector;
    theFollowersVector = UsersDataOne.getFollowersMatrix();

    // Create a QGraphicsScene to hold the graph
    QGraphicsScene* scene = new QGraphicsScene(this);

    // Define radius for the nodes and scene dimensions
    const int nodeRadius = 20;
    const int sceneWidth = 800;
    const int sceneHeight = 600;

    // Place the scene at the center of the window
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);

    // Store node positions to connect them with edges later
    QMap<int, QPointF> nodePositions;

    // Position the nodes in a circular layout
    int numUsers = theFollowersVector.size();
    double angleStep = 2 * M_PI / numUsers;
    int centerX = sceneWidth / 2;
    int centerY = sceneHeight / 2;
    int circleRadius = 200;

    for (int i = 0; i < numUsers; ++i) {
        int userId = theFollowersVector[i][0];
        double angle = i * angleStep;

        int x = centerX + circleRadius * cos(angle);
        int y = centerY + circleRadius * sin(angle);

        // Create and add the node
        QGraphicsEllipseItem* node = scene->addEllipse(x - nodeRadius, y - nodeRadius, 2 * nodeRadius, 2 * nodeRadius,
                                                       QPen(Qt::black), QBrush(Qt::blue));
        // Add text to the node
        QGraphicsTextItem* label = scene->addText(QString::number(userId));
        label->setDefaultTextColor(Qt::white);
        label->setPos(x - label->boundingRect().width() / 2, y - label->boundingRect().height() / 2);

        // Store the position for connecting edges
        nodePositions[userId] = QPointF(x, y);
    }



    // // //second
    // for (const auto& userFollowers : theFollowersVector) {
    //     int userId = userFollowers[0];
    //     QPointF userPos = nodePositions[userId];

    //     for (size_t j = 1; j < userFollowers.size(); ++j) {
    //         int followerId = userFollowers[j];
    //         if (nodePositions.contains(followerId)) {
    //             QPointF followerPos = nodePositions[followerId];

    //             // Offset for the arrow start and end
    //             QLineF line(userPos, followerPos);
    //             double length = line.length();
    //             double arrowOffset = nodeRadius + 5; // Offset by radius + padding

    //             // Calculate new start and end points
    //             QPointF lineStart = line.pointAt(arrowOffset / length);
    //             QPointF lineEnd = line.pointAt((length - arrowOffset) / length);

    //             // Draw the line
    //             QGraphicsLineItem* edge = scene->addLine(QLineF(lineStart, lineEnd), QPen(Qt::black));

    //             // Add arrowhead to the end
    //             double arrowSize = 10;
    //             double angle = std::atan2(-line.dy(), line.dx());

    //             QPointF arrowP1 = lineEnd - QPointF(sin(angle - M_PI / 6) * arrowSize, cos(angle - M_PI / 6) * arrowSize);
    //             QPointF arrowP2 = lineEnd - QPointF(sin(angle + M_PI / 6) * arrowSize, cos(angle + M_PI / 6) * arrowSize);

    //             scene->addPolygon(QPolygonF() << lineEnd << arrowP1 << arrowP2, QPen(Qt::black), QBrush(Qt::black));
    //         }
    //     }
    // }

    for (const auto& userFollowers : theFollowersVector) {
        int userId = userFollowers[0];
        QPointF userPos = nodePositions[userId];

        for (size_t j = 1; j < userFollowers.size(); ++j) {
            int followerId = userFollowers[j];
            if (nodePositions.contains(followerId)) {
                QPointF followerPos = nodePositions[followerId];

                // Offset for the arrow start and end
                QLineF line(followerPos, userPos); // Arrow from follower to user
                double length = line.length();
                double arrowOffset = nodeRadius + 5; // Offset by radius + padding

                // Calculate new start and end points
                QPointF lineStart = line.pointAt(arrowOffset / length);                     // Start near the follower
                QPointF lineEnd = line.pointAt((length - arrowOffset) / length);           // End near the user

                // Draw the line
                QGraphicsLineItem* edge = scene->addLine(QLineF(lineStart, lineEnd), QPen(Qt::black));

                // Add arrowhead to the end (near the user)
                double arrowSize = 10;
                double angle = std::atan2(-line.dy(), line.dx());

                QPointF arrowP1 = lineEnd - QPointF(sin(angle - M_PI / 6) * arrowSize, cos(angle - M_PI / 6) * arrowSize);
                QPointF arrowP2 = lineEnd - QPointF(sin(angle + M_PI / 6) * arrowSize, cos(angle + M_PI / 6) * arrowSize);

                scene->addPolygon(QPolygonF() << lineEnd << arrowP1 << arrowP2, QPen(Qt::black), QBrush(Qt::black));
            }
        }
    }



    // Set up a QGraphicsView to display the scene
    QGraphicsView* view = new QGraphicsView(scene, this);
    view->setRenderHint(QPainter::Antialiasing);
    view->setGeometry(0, 0, this->width(), this->height());
    view->show();

}

