#ifndef ANALYZERWINDOW_H
#define ANALYZERWINDOW_H

#include <QDialog>

namespace Ui {
class AnalyzerWindow;
}

class AnalyzerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AnalyzerWindow(QWidget *parent = nullptr);
    ~AnalyzerWindow();

private:
    Ui::AnalyzerWindow *ui;
};

#endif // ANALYZERWINDOW_H
