#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
//#include "main.h"
#include "qobject.h"
#include <QSqlTableModel>

class DataBase : public QObject
{
    Q_OBJECT
public:
    DataBase();
    ~DataBase();
    bool openDataBase(QString);
    // bool addDataBase(QString, bool);
    // bool addSportsmen(QString);
    // bool addObjFinal();

    /*QList<sportsman> readAllSportsmen(void);
    QList<sportsman> selectlSportsmen(QString, QString, QString);
    QList<sportsman> selectAndSortlSportsmen(QString, QString, QString);
    QSqlTableModel* getModel(QString, QString, QString);
    QList<QString> getCategories(void);                                 //получение списка всех категорий
    QList<QString> getCategoriesOnMats(void);                           //получение списка категорий на коврах
    QList<QString> getAges(QString);                                    //получение списка всех возрастов в категории
    QList<QString> getWeights(QString, QString);                        //получение списка всех весов в возрасте
    QList<sportsman> getAthlets(void);                                  //получение списка всех спортсменов
    void setPlace(QString, QString);                                    //установка места в первом круге
    int getCountThirdPlaces(void);                                      //получение количества третьих мест
    QList<QString> getCategoriesAgesWeihts(void);                       //получение всех неповторяющихся категорий
    QList<QString> getDataFinal(QString, QString, QString);             //получение данных для объекта финалов
    void writeNames(int, QList<QString>);                               //запись в базу данных имён спортсменов при установке
        //места в первом круге
    void writeFinalWinners(int, int, int, int, int);                    //запись в базу данных выигравших в финале
    void setStatus(QString, QString, QString, int);                     //статус категории (1 - на ковре)
    int addCategoryOnMat(QString, QString, QString, int, int);          //добавить категорию на ковре в базу
    int addAthleteInCategory(int, AthletOnMat);                         //
    QList<QString> getAthletesOnMats(QString);                          //
    QList<QString> removeCategoryFromMat(int);                          //удаление категории с ковра
    QList<QString> getCategoryAgeWeightById(int);                       //получить название категории, возраст и вес по id категории
    QList<int> findCategoryOnMats(QString, QString, QString);           //поиск категории на коврах

    int getCountAthelets(QString, QString, QString);                    //получить количество спортсменов в категории

    void createBaseOnMat(QString);                                 */     //создание баз данных для ковров

private:
    QSqlDatabase db;
    int mat = 0;    // ковёр: 0 - А, 1 - Б
    QSqlQuery* query;

public slots:

    ///////////////////////////////////////////////////////////////////////////////
    /// вставка строки в таблицу "first_round" при отправке спортсмена на ковёр ///
    ///////////////////////////////////////////////////////////////////////////////
    // void addItemOnMat(int   // id спортсмена
    //                   , sportsman
    //                   //int   // ковёр: 0 - А, 1 - Б
    //                   );

    //////////////////////////////////////////////////
    /// вставка данных из сокета для первого круга ///
    //////////////////////////////////////////////////
    // void addData(int,               // id спортсмена
    //              QVector<float>,    // 15 оценок
    //              float              // сумма баллов
    //              );

    //void setMat(int);

signals:
    //void setStatus(QString);
    //void changeItems(void);

    ////////////////////////////////
    /// изменения в первом круге ///
    ////////////////////////////////
    // void sigFirst(int,              // id спортсмена
    //               QVector<float>,   // оценки (3х5=15)
    //               float,            // сумма баллов
    //               int               // дополнительная оценка
    //               );

    // void update_half(int);      // изменения в полуфинале
    // void update_final(int);     // изменения в финале
    // void update_third(int);     // изменения в розыгрыше за третья место

};

#endif // DATABASE_H
