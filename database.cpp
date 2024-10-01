#include "database.h"
#include <QMessageBox>
#include <QLabel>

DataBase::DataBase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    query = new QSqlQuery;


}

DataBase::~DataBase(){
    if(db.open())
        db.close();
}

bool DataBase::openDataBase(QString name)
{
    qDebug()<<"name = "<<name;
    if (db.open())
        db.close();
    db.setDatabaseName(name);
    if (!db.open())
        return false;
    qDebug()<<"open db true";
    return true;
}



// void DataBase::createBaseOnMat(QString name){
//     QString base = name;
//     //QString base1, base2, base3;
//     base.truncate(base.length() - 3);
//     QList<QString> listBase;
//     listBase.append(base + "_mat1.db");
//     listBase.append(base + "_mat2.db");
//     listBase.append(base + "_mat3.db");
//     //qDebug()<<"name = "<<base1<<base2<<base3;
//     // if (db.open())
//     //     db.close();
//     // db.setDatabaseName(name);
//     // if (!db.open())
//     //     return false;
//     QString sCategories =   "CREATE TABLE categories "
//                           "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
//                           "category  TEXT, age TEXT, weight TEXT,  mode INTEGER)";

//     QString sAthletes =     "CREATE TABLE athletes "
//                         "(id INTEGER PRIMARY KEY AUTOINCREMENT, id_category INTEGER, "
//                         "name  TEXT, region TEXT, range TEXT,  belt INTEGER, "
//                         "rate11 REAL, rate12 REAL, rate13 REAL, rate14 REAL, rate15 REAL, "
//                         "rate21 REAL, rate22 REAL, rate23 REAL, rate24 REAL, rate25 REAL, "
//                         "rate31 REAL, rate32 REAL, rate33 REAL, rate34 REAL, rate35 REAL, "
//                         "rate41 REAL, rate42 REAL, rate43 REAL, rate44 REAL, rate45 REAL, "
//                         "rate51 REAL, rate52 REAL, rate53 REAL, rate54 REAL, rate55 REAL, "
//                         "addRate TEXT, place INTEGER)";

//     foreach(QString str, listBase){
//         db.setDatabaseName(str);
//         if (!db.open()){
//             qDebug()<<str + " не создана";
//             break;
//         }
//         if(!query->exec(sCategories)){
//             qDebug()<<"ошибка создания таблицы categories " + db.lastError().text();
//             db.close();
//             break;
//         }
//         if(!query->exec(sAthletes)){
//             qDebug()<<"ошибка создания таблицы athletes " + db.lastError().text();
//             db.close();
//             break;
//         }
//         db.close();
//     }
// }

// bool DataBase::addSportsmen(QString str)
// {
//     //QSqlQuery query;
//     query->exec(" PRAGMA synchronous = OFF, journal_mode = MEMORY");
//     QVariantList names;
//     QVariantList regions;
//     QVariantList categories;
//     QVariantList ages;
//     QVariantList weights;
//     QVariantList range;
//     query->prepare("INSERT INTO sportsmen (name, region, category, age, weight, range ) "
//                    "VALUES (?, ?, ?, ?, ?, ?)");
//     foreach(QString str, str.removeLast().split("\n")){
//         QStringList sList = str.split("\t");
//         names.append(sList.at(0));
//         regions.append(sList.at(1));
//         categories.append(sList.at(5));
//         ages.append(sList.at(2));
//         weights.append(sList.at(3));
//         range.append(sList.at(4));
//     }

//     query->addBindValue(names);
//     query->addBindValue(regions);
//     query->addBindValue(categories);
//     query->addBindValue(ages);
//     query->addBindValue(weights);
//     query->addBindValue(range);

//     if (!query->execBatch())
//         qDebug() << query->lastError();

//     return true;
// }

// QList<sportsman> DataBase::readAllSportsmen()
// {
//     QVector<sportsman> listSportsmens;
//     //QSqlQuery query;
//     sportsman sMan;
//     query->exec("SELECT * FROM sportsmen");
//     while(query->next()){
//         sMan.name = query->value("name").toString();
//         sMan.region = query->value("region").toString();
//         sMan.weight = query->value("weight").toString();
//         sMan.age = query->value("age").toString();
//         sMan.category = query->value("category").toString();
//         sMan.range = query->value("range").toString();
//         sMan.place = query->value("place").toInt();
//         sMan.status = query->value("status").toBool();
//         listSportsmens.append(sMan);
//     }

//     return listSportsmens;
// }

// QList<sportsman> DataBase::selectlSportsmen(QString c, QString a, QString w)
// {
//     QVector<sportsman> listSportsmens;
//     //QSqlQuery query;
//     QString sql("SELECT * FROM sportsmen WHERE category = '%1' and age = '%2' and weight = '%3'");
//     query->exec(sql.arg(c, a, w));
//     while(query->next()){
//         sportsman sMan;
//         sMan.name = query->value("name").toString();
//         sMan.region = query->value("region").toString();
//         sMan.weight = query->value("weight").toString();
//         sMan.age = query->value("age").toString();
//         sMan.category = query->value("category").toString();
//         sMan.range = query->value("range").toString();
//         sMan.status = query->value("status").toInt();
//         listSportsmens.append(sMan);
//     }
//     return listSportsmens;
// }

// QList<sportsman> DataBase::selectAndSortlSportsmen(QString c, QString a, QString w)
// {
//     QVector<sportsman> listSportsmens;
//     //QSqlQuery query;
//     QString sql("SELECT * FROM sportsmen WHERE category = '%1' and age = '%2' and weight = '%3'");
//     query->exec(sql.arg(c, a, w));
//     while(query->next()){
//         sportsman sMan;
//         sMan.id = query->value("id").toInt();
//         sMan.name = query->value("name").toString();
//         sMan.region = query->value("region").toString();
//         sMan.weight = query->value("weight").toString();
//         sMan.age = query->value("age").toString();
//         sMan.category = query->value("category").toString();
//         sMan.range = query->value("range").toString();
//         sMan.status = query->value("status").toInt();
//         listSportsmens.append(sMan);
//     }
//     return listSportsmens;
// }

// QSqlTableModel* DataBase::getModel(QString c, QString a, QString w)
// {
//     QSqlTableModel* model = new QSqlTableModel;
//     model->setTable("sportsmen");

//     QString filter = "category = '%1' and age = '%2' and weight = '%3'";
//     filter = filter.arg(c).arg(a).arg(w);
//     model->setFilter (filter);

//     model->select();




//     return model;
// }

// //////////////////////////////////
// /// Получение списка категорий ///
// //////////////////////////////////
// QList<QString> DataBase::getCategories()
// {
//     QList<QString> listCategories;
//     //QSqlQuery query;
//     QString sql("SELECT DISTINCT category FROM sportsmen ORDER BY category ");
//     query->exec(sql);
//     while(query->next())
//         listCategories.append(query->value(0).toString());
//     return listCategories;

// }

// QList<QString> DataBase::getCategoriesOnMats()
// {
//     QList<QString> listCategories;
//     //QSqlQuery query;
//     QString sql("SELECT *  FROM categoryes_on_mats ");
//     if(!query->exec(sql))
//         qDebug()<<"Ошибка вставки в таблицу settings " + query->lastError().text();
//     while(query->next())
//         listCategories.append(query->value(0).toString() + ";" +
//                               query->value(1).toString() + ";" +
//                               query->value(2).toString() + ";" +
//                               query->value(3).toString() + ";" +
//                               query->value(4).toString() + ";" +
//                               query->value(5).toString() + ";" +
//                               query->value(6).toString());
//     return listCategories;
// }

// ///////////////////////////////////////////////////
// /// Получение списка всех возрастов в категории ///
// ///////////////////////////////////////////////////
// QList<QString> DataBase::getAges(QString category)
// {
//     QList<QString> listAges;
//     //QSqlQuery query;
//     QString sql("SELECT DISTINCT age FROM sportsmen WHERE category = '%1' ORDER BY age ");
//     sql = sql.arg(category);
//     query->exec(sql);
//     while(query->next())
//         listAges.append(query->value(0).toString());
//     return listAges;
// }

// //////////////////////////////////////////////
// /// Получение списка всех весов в возрасте ///
// //////////////////////////////////////////////
// QList<QString> DataBase::getWeights(QString age, QString category)
// {
//     QList<QString> listWeights;
//     //QSqlQuery query;
//     QString sql("SELECT DISTINCT weight FROM sportsmen WHERE age = '%1' AND category = '%2' ORDER BY weight ");
//     sql = sql.arg(age, category);
//     query->exec(sql);
//     while(query->next())
//         listWeights.append(query->value(0).toString());
//     return listWeights;
// }

// QList<sportsman> DataBase::getAthlets()
// {
//     QList<sportsman> listAthlets;
//     //QSqlQuery query;
//     QString sql("SELECT * FROM sportsmen ");
//     query->exec(sql);
//     while(query->next()){
//         sportsman sMan;
//         sMan.id = query->value("id").toInt();
//         sMan.name = query->value("name").toString();
//         sMan.region = query->value("region").toString();
//         sMan.weight = query->value("weight").toString();
//         sMan.age = query->value("age").toString();
//         sMan.category = query->value("category").toString();
//         sMan.range = query->value("range").toString();
//         sMan.status = query->value("status").toInt();
//         sMan.place = query->value("place").toInt();
//         listAthlets.append(sMan);
//     }
//     return listAthlets;
// }

// void DataBase::setPlace(QString place, QString id)
// {
//     QString sql("UPDATE sportsmen SET place = %1 WHERE id = %2;");
//     query->exec(sql.arg(place, id));
// }

// int DataBase::getCountThirdPlaces()
// {
//     int countPlaces = 1;
//     QString sql("SELECT countThirdPlaces FROM settings ");
//     query->exec(sql);
//     if(query->next())
//         countPlaces = query->value(0).toInt();
//     return countPlaces;
// }

// QList<QString> DataBase::getCategoriesAgesWeihts()
// {
//     QList<QString> list;
//     QString sql("SELECT DISTINCT category, age, weight FROM sportsmen;");
//     query->exec(sql);
//     while(query->next())
//         list.append(query->value(0).toString() + ";"
//                     + query->value(1).toString() + ";"
//                     + query->value(2).toString());
//     return list;
// }

// QList<QString> DataBase::getDataFinal(QString category, QString age, QString weight)
// {
//     QList<QString> list;
//     QString sql("SELECT * FROM final WHERE category = '%1' AND age = '%2' AND weight = '%3'");
//     query->exec(sql.arg(category, age, weight));
//     if(query->next()){
//         list.append(query->value("id").toString());
//         list.append(query->value("name1").toString());
//         list.append(query->value("name2").toString());
//         list.append(query->value("name3").toString());
//         list.append(query->value("name4").toString());
//         list.append(query->value("status").toString());
//         list.append(query->value("winSemiOne").toString());
//         list.append(query->value("winSemiTwo").toString());
//         list.append(query->value("winFinal").toString());
//         list.append(query->value("winFinalThird").toString());
//         list.append(query->value("rateSemiFin1").toString());
//         list.append(query->value("rateSemiFin2").toString());
//         list.append(query->value("rateSemiFin3").toString());
//         list.append(query->value("rateSemiFin4").toString());
//         list.append(query->value("addRateSemiFin1").toString());
//         list.append(query->value("addRateSemiFin2").toString());
//         list.append(query->value("addRateSemiFin3").toString());
//         list.append(query->value("addRateSemiFin4").toString());
//         list.append(query->value("rateFin1").toString());
//         list.append(query->value("rateFin2").toString());
//         list.append(query->value("addRateFin1").toString());
//         list.append(query->value("addRateFin2").toString());
//         list.append(query->value("rateThird1").toString());
//         list.append(query->value("rateThird2").toString());
//         list.append(query->value("addRateThird1").toString());
//         list.append(query->value("addRateThird2").toString());
//         return list;
//     }
//     else {
//         sql = "INSERT INTO final (category, age, weight) VALUES ('%1', '%2', '%3') ";
//         query->exec(" PRAGMA synchronous = OFF, journal_mode = MEMORY");
//         if(!query->exec(sql.arg(category, age, weight)))
//             qDebug()<<"error insert final"<<query->lastError();
//         list.append(query->lastInsertId().toString());
//         qDebug()<<"query.lastInsertId().toString() = "<<query->lastInsertId().toString();
//         return list;
//     }
// }

// void DataBase::writeNames(int id, QList<QString> l)
// {
//     QString sql("UPDATE final SET name1 = '%1', "
//                 "name2 = '%2', "
//                 "name3 = '%3', "
//                 "name4 = '%4' WHERE id = %5;");
//     if(!query->exec(sql.arg(l.at(0), l.at(1), l.at(2), l.at(3), QString::number(id))))
//         qDebug()<<"error update names"<<query->lastError();
// }

// void DataBase::writeFinalWinners(int id, int winSemiOne, int winSemiTwo, int winFinal, int winFinalThird)
// {
//     qDebug()<<"baza "<<winSemiOne<<winSemiTwo<<winFinal<<winFinalThird;
//     QString sql("UPDATE final SET winSemiOne    = %1, "
//                 "                 winSemiTwo    = %2, "
//                 "                 winFinal      = %3, "
//                 "                 winFinalThird = %4 "
//                 "                 WHERE id      = %5;");
//     if(!query->exec(sql.arg(QString::number(winSemiOne),
//                              QString::number(winSemiTwo),
//                              QString::number(winFinal),
//                              QString::number(winFinalThird),
//                              QString::number(id))))
//         qDebug()<<"error update winners"<<query->lastError();
// }

// void DataBase::setStatus(QString category, QString age , QString weight, int status)
// {
//     QString sql("UPDATE sportsmen SET status    = %1 "
//                 "WHERE category = '%2' AND age = '%3' AND weight = '%4';");
//     if(!query->exec(sql.arg(QString::number(status),
//                              category,
//                              age,
//                              weight)))
//         qDebug()<<"error update status"<<query->lastError();
// }

// int DataBase::addCategoryOnMat(QString category, QString age, QString weight, int mat, int mode)
// {
//     QString sql = "INSERT INTO categoryes_on_mats (category, age, weight, mat, mode) VALUES ('%1', '%2', '%3', '%4', '%5') ";
//     query->exec(" PRAGMA synchronous = OFF, journal_mode = MEMORY");
//     if(!query->exec(sql.arg(category, age, weight, QString::number(mat), QString::number(mode))))
//         qDebug()<<"error insert categoryes_on_mats"<<query->lastError();
//     return query->lastInsertId().toString().toInt();
// }

// int DataBase::addAthleteInCategory(int id, AthletOnMat athlete)
// {
//     QString sql = "INSERT INTO athletes_on_mats (id_category, name, region, range) VALUES (%1, '%2', '%3', '%4') ";
//     query->exec(" PRAGMA synchronous = OFF, journal_mode = MEMORY");
//     if(!query->exec(sql.arg(QString::number(id), athlete.name, athlete.region, athlete.range)))
//         qDebug()<<"error insert athletes_on_mats"<<query->lastError();
//     return query->lastInsertId().toString().toInt();
// }

// QList<QString> DataBase::getAthletesOnMats(QString id)
// {
//     QString sql("SELECT * FROM athletes_on_mats WHERE id_category = %1;");
//     query->exec(sql.arg(id));
//     QList<QString> sList;
//     while(query->next()){
//         QString name(query->value(2).toString() + ";" +
//                      query->value(3).toString() + ";" +
//                      query->value(4).toString());
//         QString rate11(query->value(5).toString());
//         QString rate12(query->value(6).toString());
//         QString rate13(query->value(7).toString());
//         QString rate21(query->value(8).toString());
//         QString rate22(query->value(9).toString());
//         QString rate23(query->value(10).toString());
//         QString rate31(query->value(11).toString());
//         QString rate32(query->value(12).toString());
//         QString rate33(query->value(13).toString());
//         QString rate41(query->value(14).toString());
//         QString rate42(query->value(15).toString());
//         QString rate43(query->value(16).toString());
//         QString rate51(query->value(17).toString());
//         QString rate52(query->value(18).toString());
//         QString rate53(query->value(19).toString());
//         QString color(query->value(20).toString());
//         QString addrate(query->value(21).toString());
//         sList.append(name + ";" +
//                      rate11 + ";" + rate12 + ";" + rate13 + ";" +
//                      rate21 + ";" + rate22 + ";" + rate23 + ";" +
//                      rate31 + ";" + rate32 + ";" + rate33 + ";" +
//                      rate41 + ";" + rate42 + ";" + rate43 + ";" +
//                      rate51 + ";" + rate52 + ";" + rate53 + ";" +
//                      color + ";" + addrate);
//     }
//     return sList;
// }

// QList<QString> DataBase::removeCategoryFromMat(int id)
// {
//     // QString sql("SELECT category, age, weight FROM categoryes_on_mats WHERE id = %1");
//     // if(!query->exec(sql.arg(id)))
//     //     qDebug()<<"error SELECT category, age, weight"<<query->lastError();
//     // QList<QString> retList;
//     // query->next();
//     // retList.append(query->value("category").toString());
//     // retList.append(query->value("age").toString());
//     // retList.append(query->value("weight").toString());
//     QList<QString> retList = getCategoryAgeWeightById(id);
//     QString sql = "DELETE FROM categoryes_on_mats WHERE id = %1";
//     if(!query->exec(sql.arg(id)))
//         qDebug()<<"error DELETE categoryes_on_mats"<<query->lastError();
//     sql = "DELETE FROM athletes_on_mats WHERE id_category = %1";
//     if(!query->exec(sql.arg(id)))
//         qDebug()<<"error DELETE athletes_on_mats"<<query->lastError();
//     return retList;
// }

// QList<QString> DataBase::getCategoryAgeWeightById(int id)
// {
//     QString sql("SELECT category, age, weight FROM categoryes_on_mats WHERE id = %1");
//     if(!query->exec(sql.arg(id)))
//         qDebug()<<"error SELECT category, age, weight"<<query->lastError();
//     QList<QString> retList;
//     query->next();
//     retList.append(query->value("category").toString());
//     retList.append(query->value("age").toString());
//     retList.append(query->value("weight").toString());
//     return retList;
// }

// QList<int> DataBase::findCategoryOnMats(QString cat, QString age, QString weight)
// {
//     QString sql("SELECT id, mat FROM categoryes_on_mats WHERE category = '%1' AND age = '%2' AND weight = '%3'");
//     if(!query->exec(sql.arg(cat, age, weight)))
//         qDebug()<<"error findCategoryOnMats"<<query->lastError();
//     QList<int> retList;
//     if(query->next()){
//         retList.append(query->value("id").toInt());
//         retList.append(query->value("mat").toInt());
//         return retList;
//     }
//     return retList;
// }

// int DataBase::getCountAthelets(QString cat, QString age, QString weight)
// {
//     QString sql("SELECT COUNT(*) FROM sportsmen WHERE category = '%1' AND age = '%2' AND weight = '%3'");
//     if(!query->exec(sql.arg(cat, age, weight)))
//         qDebug()<<"error getCountAthelets"<<query->lastError();
//     if(query->first())
//         return query->value(0).toInt();
//     return 0;
// }

// void DataBase::addItemOnMat(int id, sportsman)
// {
//     query->exec(" PRAGMA synchronous = OFF, journal_mode = MEMORY");
//     query->prepare("INSERT INTO first_round (id_sportsman, status, mat) VALUES (?, ?, ?)");
//     query->addBindValue(id);
//     query->addBindValue(0);
//     query->addBindValue(mat);
//     query->exec();
//     query->prepare("UPDATE sportsmen SET status = ? WHERE id = ?;");
//     query->addBindValue(1);
//     query->addBindValue(id);
//     query->exec();
// }

// void DataBase::addData(int id, QVector<float> rates, float total)
// {
//     QString sql("SELECT * FROM first_round WHERE id_sportsmam = '%1'");
//     query->exec(sql.arg(id));
//     if(query->next()){       //

//     }
//     else{

//     }

//     emit sigFirst(id, rates, total, 0);
// }

// void DataBase::setMat(int m)
// {
//     mat = m;
// }
