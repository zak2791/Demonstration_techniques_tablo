#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QTcpServer>

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

    QTimer* tmrStatus;                  //

    void fillLastCompetitions(void);    //заполнение меню последних соревнований

    QUdpSocket* udpSocket;              //Проверка подключения к секретарю
    QTcpServer* tcpServer;              //
    QTcpSocket* tcpSocket;              //
    QHostAddress* host;                 //адрес компьютера секретаря


private slots:
    void choiceCompetitions(void);      //выбор соревнования
    void processPendingDatagrams(void);
    void slotStatus(void);
    void slotNewTcpConnection(void);

};
#endif // MAINWINDOW_H
