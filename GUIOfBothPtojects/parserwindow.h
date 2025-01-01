#ifndef PARSERWINDOW_H
#define PARSERWINDOW_H

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
//#include "XmlParser/XmlParser.h"
//#include "XmlParser/Tags_utilities.h"

#include "XmlParser.cpp"



QT_BEGIN_NAMESPACE
namespace Ui {
class ParserWindow;
}
QT_END_NAMESPACE

class ParserWindow : public QDialog
{
    Q_OBJECT

public:
    ParserWindow(QWidget *parent = nullptr);
    ~ParserWindow();

private slots:


    void on_textEdit_textChanged();
    bool saveToFile(const QString &filePath, const QString &content);


    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_Prettifybtn_clicked();

    /*void on_Detectbtn_clicked();

    void on_correctbtn_clicked();
*/
    void on_Compressbtn_clicked();
    /*
    void on_Decompressbtn_clicked();

    void on_XMLExpButton_clicked();

    void on_JsonExpButton_clicked();*/

    void on_Minifybtn_clicked();

    //void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_textEdit_copyAvailable(bool b);

    void on_listView_activated(const QModelIndex &index);

    void on_ImportButton_clicked();

    void on_listView_windowTitleChanged(const QString &title);


    //void on_XMLExpButton_clicked();


    void on_XMLExpButton_clicked();

    void on_Detectbtn_clicked();

    void on_correctbtn_clicked();

    void on_JsonExpButton_clicked();

    void on_Decompressbtn_clicked();

private:
    Ui::ParserWindow *ui;
    QStringListModel *model;
    QListView *listView;
    QStandardItemModel *model_1;
    void loadXMLAsPlainText(const QString &filePath);
    void loadXMLFromText(const QString &text);
    void displayVectorInListWidget(const vector <Error>& vec , QListWidget* listWidget);
};
#endif // PARSERWINDOW_H
