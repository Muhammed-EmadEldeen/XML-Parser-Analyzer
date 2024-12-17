#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QListView *listView;
    QStandardItemModel *model_1;
    void loadXMLAsPlainText(const QString &filePath);
    void loadXMLFromText(const QString &text);
};
#endif // MAINWINDOW_H
