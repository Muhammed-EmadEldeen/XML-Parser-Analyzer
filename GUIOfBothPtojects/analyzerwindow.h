#ifndef ANALYZERWINDOW_H
#define ANALYZERWINDOW_H

#include <QDialog>

#include <QFileDialog>
#include <string>

//
#include <QDialog>
#include <QListView>
#include <QStringListModel>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QListWidgetItem>

//

#include "User.h"
#include "UsersData.h"
// #include "GraphVisualisation.h"

using namespace std;

//

//

namespace Ui {
class AnalyzerWindow;
}

class AnalyzerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AnalyzerWindow(QWidget *parent = nullptr);
    ~AnalyzerWindow();

private slots:
    void on_dirBtn_clicked();

    void on_parseXmlFileBtn_clicked();

    void on_getMostFollowedUserBtn_clicked();

    void on_getMostFollowingUserBtn_clicked();

    void on_pushButton_clicked();

    void on_mutualFollowersBtn_clicked();

    void on_getPostsByWordBtn_clicked();

    void on_getPostsByTopicBtn_clicked();

private:
    Ui::AnalyzerWindow *ui;
    //void displayVectorInListWidget(const vector<string>& vOut , QListWidget* listWidget);

};

#endif // ANALYZERWINDOW_H
