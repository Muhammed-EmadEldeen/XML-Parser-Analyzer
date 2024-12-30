#include "analyzerwindow.h"
#include "ui_analyzerwindow.h"
#include "User.h"
#include "UsersData.h"

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
    MostFollowingUser= UsersDataOne.getMostFollowedUser();
    ui->getMostFollowedUserLbl->setText(QString::fromStdString(MostFollowingUser.getName()));
}


void AnalyzerWindow::on_parseXmlFileBtn_clicked()
{
    UsersDataOne.parseXmlFile(filePath);
    ui->parseXmlFileLbl->setText("Done");

}

