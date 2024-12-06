#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QFileDialog>
#include <QStandardItemModel>


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
    void on_pushButton_clicked();

    void on_label_linkActivated(const QString &link);

        void onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);  // Add this for selection change
    void on_listView_indexesMoved(const QModelIndex &index);  // Declare the slot here


    void on_listView_indexesMoved(const QModelIndexList &indexes);

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QListView *listView;
    QStandardItemModel *model_1;
    void loadXMLAsPlainText(const QString &filePath);
};
#endif // MAINWINDOW_H
