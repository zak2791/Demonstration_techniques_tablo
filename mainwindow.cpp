#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QActionGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manageBase = new DataBase;
    //ui->control->setSource(QUrl("qrc:/Control.qml"));
    lastCompetitions = ui->menu->addMenu("Последние");
    lastCompetitions->setEnabled(false);
    lblStatus = new QLabel();
    statusBar()->addWidget(lblStatus);
    fillLastCompetitions();

    udpSocket = new QUdpSocket(this);

    udpSocket->bind(10123, QUdpSocket::ShareAddress);

    connect(udpSocket, &QUdpSocket::readyRead,
            this, &MainWindow::processPendingDatagrams);

    tmrStatus = new QTimer(this);
    connect(tmrStatus, SIGNAL(timeout()), this, SLOT(slotStatus()));
    tmrStatus->start(3000);

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(slotNewTcpConnection()));
    tcpServer->listen(QHostAddress::Any, 50001);

    host = new QHostAddress();
    hostSectetary = new QHostAddress();
    //flagConnectToSecretary = false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete host;
}

void MainWindow::processPendingDatagrams()
{
    QByteArray datagram;
    while (udpSocket->hasPendingDatagrams()) {
        quint16 port;
        datagram.resize(int(udpSocket->pendingDatagramSize()));
        udpSocket->readDatagram(datagram.data(), datagram.size(), host, &port);
        qDebug()<<*host<<port;
        QString sData = datagram.data();
        QString copyCurrent = currentActionLast;
        copyCurrent.truncate(copyCurrent.lastIndexOf(QChar('_')));
        if(sData != "" && sData == copyCurrent){
            udpSocket->writeDatagram(currentActionLast.last(1).toUtf8(), *host, port);
            lblStatus->setStyleSheet("color: green;");
            tmrStatus->stop();
            tmrStatus->start(3000);
            //flagConnectToSecretary = true;
            *hostSectetary = *host;
        }
        else{
            //flagConnectToSecretary = false;
            hostSectetary->clear();
        }
    }
}

void MainWindow::slotStatus(){
    lblStatus->setStyleSheet("color: red;");
    //flagConnectToSecretary = false;
    hostSectetary->clear();
}

void MainWindow::slotNewTcpConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();
    if(hostSectetary->isNull()){
        tcpSocket->close();
            return;
    }

    connect(tcpSocket, &QTcpSocket::readyRead, this, [=](){
        QByteArray arr = tcpSocket->readAll();
        qDebug()<<arr;
        tcpSocket->write(arr);
    ;});
    tcpSocket->waitForReadyRead(10000);
    tcpSocket->close();
}

//////////////////////////////////////////////
/// Заполнение меню последних соревнований ///
//////////////////////////////////////////////
void MainWindow::fillLastCompetitions(){
    QDir dir = QDir::current();
    QFileInfoList lFiles = dir.entryInfoList({"*.db"}, QDir::Files, QDir::Time);
    if(lFiles.count() > 0){
        QActionGroup* gr = new QActionGroup(this);
        foreach(QFileInfo inf, lFiles){
            QAction* act = gr->addAction(inf.completeBaseName());
            act->setCheckable(true);
            connect(act, SIGNAL(triggered()), this, SLOT(choiceCompetitions()));
        }
        lastCompetitions->clear();
        lastCompetitions->addActions(gr->actions());
        lastCompetitions->setEnabled(true);
    }
    //m->clearModel();
}

//////////////////////////////////////
/// Открыть последние соревнования ///
//////////////////////////////////////
void MainWindow::choiceCompetitions()
{
    if(static_cast<QAction*>(sender())->text() != currentActionLast){
        currentActionLast = static_cast<QAction*>(sender())->text();
        if(manageBase->openDataBase(currentActionLast + ".db")) {
            QString copyCurrent = currentActionLast;
            QString mat = " Ковер " + currentActionLast.last(1);
            copyCurrent.truncate(copyCurrent.lastIndexOf(QChar('_')));
            lblStatus->setText(copyCurrent + mat);
            QString port = "5000" + currentActionLast.last(1);
            if(tcpServer->isListening())
                tcpServer->close();
            tcpServer->listen(QHostAddress::Any, port.toInt());
        }
    }
    //add->setEnabled(true);
    //addBuffer->setEnabled(true);
    //countThirdPlaces = manageBase->getCountThirdPlaces();
    //m->clearModel();
    //fillListCategoryes();
    //fillCategories();
}
