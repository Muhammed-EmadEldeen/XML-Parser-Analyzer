#ifndef ANALYZERWINDOW_H
#define ANALYZERWINDOW_H

#include <QDialog>

#include <QFileDialog>

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

private:
    Ui::AnalyzerWindow *ui;
};

#endif // ANALYZERWINDOW_H
