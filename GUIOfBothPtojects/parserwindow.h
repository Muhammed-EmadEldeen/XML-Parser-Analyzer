#ifndef PARSERWINDOW_H
#define PARSERWINDOW_H

#include <QDialog>

namespace Ui {
class ParserWindow;
}

class ParserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ParserWindow(QWidget *parent = nullptr);
    ~ParserWindow();

private:
    Ui::ParserWindow *ui;
};

#endif // PARSERWINDOW_H
