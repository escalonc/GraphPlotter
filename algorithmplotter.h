#ifndef ALGORITHMPLOTTER_H
#define ALGORITHMPLOTTER_H

#include <QMainWindow>
#include "container.h"
#include <vector>

namespace Ui {
class AlgorithmPlotter;
}

class AlgorithmPlotter : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlgorithmPlotter(Container *scene, QWidget *parent = 0);
    ~AlgorithmPlotter();

private:
    Ui::AlgorithmPlotter *ui;
    Container *scene;

};

#endif // ALGORITHMPLOTTER_H
