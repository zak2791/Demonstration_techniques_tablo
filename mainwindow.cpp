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
}

MainWindow::~MainWindow()
{
    delete ui;
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
        if(manageBase->openDataBase(currentActionLast + ".db")) lblStatus->setText(currentActionLast);
    }
    //add->setEnabled(true);
    //addBuffer->setEnabled(true);
    //countThirdPlaces = manageBase->getCountThirdPlaces();
    //m->clearModel();
    //fillListCategoryes();
    //fillCategories();
}
