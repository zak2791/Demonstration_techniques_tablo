#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

#include "database.h"

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

private:
    Ui::MainWindow *ui;

    DataBase* manageBase;

    QMenu* lastCompetitions;            //меню последних соревнований
    QString currentActionLast = "";     //текущее соревнование

    QLabel* lblStatus;                  //надбись в статусбаре

    void fillLastCompetitions(void);    //заполнение меню последних соревнований

private slots:
    void choiceCompetitions(void);      //выбор соревнования

};
#endif // MAINWINDOW_H
