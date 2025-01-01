#ifndef GRAPHVISUALISATION_H
#define GRAPHVISUALISATION_H

#include <QDialog>

namespace Ui {
class GraphVisualisation;
}

class GraphVisualisation : public QDialog
{
    Q_OBJECT

public:
    explicit GraphVisualisation(QWidget *parent = nullptr);
    ~GraphVisualisation();

private:
    Ui::GraphVisualisation *ui;
};

#endif // GRAPHVISUALISATION_H
