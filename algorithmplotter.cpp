#include "algorithmplotter.h"
#include "ui_algorithmplotter.h"

AlgorithmPlotter::AlgorithmPlotter(Container *scene, QWidget *parent) :
    scene(scene),
    QMainWindow(parent),
    ui(new Ui::AlgorithmPlotter)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
}

AlgorithmPlotter::~AlgorithmPlotter()
{
    delete scene;
    delete ui;
}
