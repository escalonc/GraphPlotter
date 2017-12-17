#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "point.h"
#include "container.h"
#include "algorithmplotter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Container *scene;
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    AlgorithmPlotter *algorithmPlotter;
};

#endif // MAINWINDOW_H
