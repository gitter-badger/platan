#include <QString>
#include <sqlitedate.h>
#include <sqlinsert.h>
#include <sqlupdate.h>
#include <sqlselect.h>
#include <tablestructure.h>
#include <QSqlQuery>
#include <string>

#include "tst_sqlite.h"

using namespace std;

void SQLiteTest::equalsQDate()
{
    QDate qDate(2014, 2, 23);
    SQLiteDate sqlDate(qDate);
    QCOMPARE((QDate)sqlDate, qDate);
}

void SQLiteTest::equalsInt()
{
    for (int i = 0; i < 100; ++i)
    {
        int day = i * 101;
        SQLiteDate sqlDate(day);
        QCOMPARE(sqlDate.toInt(), day);
    }
}

void SQLiteTest::createSQLInsert1()
{
    SQLInsert insert("Cars");
    insert.set("color", QString("blue"));
    insert.set("brand", QString("volkswagen"));
    QCOMPARE(insert.toString(), QString("INSERT INTO Cars (color, brand) VALUES (\"blue\", \"volkswagen\")"));
}

void SQLiteTest::createSQLInsert2()
{
    SQLInsert insert("Cars");
    insert.set("varrianty", 2);
    insert.set("brand", QString("volkswagen"));
    QCOMPARE(insert.toString(), QString("INSERT INTO Cars (varrianty, brand) VALUES (2, \"volkswagen\")"));
}

void SQLiteTest::createSQLUpdate1()
{
    SQLUpdate update("Cars");
    update.set("color", QString("red"));
    update.set("brand", QString("opel"));

    QCOMPARE(update.toString(), QString("UPDATE Cars SET color = \"red\", brand = \"opel\""));
}


void SQLiteTest::createSQLUpdate2()
{
    SQLUpdate update("Cars");
    update.set("color", QString("red"));
    update.set("brand", QString("opel"));
    update.where("color = \"blue\"");
    update.where("brand = \"volkswagen\"");

    QCOMPARE(update.toString(), QString("UPDATE Cars SET color = \"red\", brand = \"opel\" WHERE color = \"blue\" AND brand = \"volkswagen\""));
}

void SQLiteTest::createSQLSelect1()
{
    SQLSelect select{"Cars"};
    select.field("color");
    select.field("brand");

    QCOMPARE(select.toString(), QString("SELECT color, brand FROM Cars"));
}

void SQLiteTest::createSQLSelect2()
{
    SQLSelect select{"Cars"};
    select.field("color");
    select.field("brand");
    select.where("color = \"blue\"");

    QCOMPARE(select.toString(), QString("SELECT color, brand FROM Cars WHERE color = \"blue\""));

}


void SQLiteTest::createSQLSelect3()
{
    SQLSelect select{"Cars"};
    select.field("color");
    select.field("brand");
    select.where("color = \"blue\"");
    select.groupBy("color");

    QCOMPARE(select.toString(), QString("SELECT color, brand FROM Cars WHERE color = \"blue\" GROUP BY color"));

}

void SQLiteTest::tableStructureEquality()
{
    TableStructure ts1("table1");
    ts1.addField("name1", SQLType::Integer());
    ts1.addField("name2", SQLType::Numeric());
    TableStructure ts2("table1");
    ts2.addField("name1", SQLType::Integer());
    ts2.addField("name2", SQLType::Numeric());
    QCOMPARE(ts1, ts2);
    ts2.addField("name3", SQLType::Numeric());
    QVERIFY(ts1 != ts2);
}

void SQLiteTest::parseSchema()
{
    QString schema{"CREATE TABLE rules (Payee INTEGER, Type INTEGER, Column INTEGER, Value TEXT, Class INTEGER)"};
    TableStructure ts1 = TableStructure::fromSchema(schema);
    QVERIFY(ts1.isValid());
    TableStructure ts2("rules");
    ts2.addField("Payee", SQLType::Integer());
    ts2.addField("Type", SQLType::Integer());
    ts2.addField("Column", SQLType::Integer());
    ts2.addField("Value", SQLType::Text());
    ts2.addField("Class", SQLType::Integer());
    QCOMPARE(ts1, ts2);
    QCOMPARE(schema, ts2.sqlCommand());
}

void SQLiteTest::parseSchema2()
{
    QString schema{"CREATE TABLE classes (\n    \"En\" TEXT,\n    \"De\" TEXT,\n    \"Hu\" TEXT,\n    \"ID\" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL\n)"};
    TableStructure ts1 = TableStructure::fromSchema(schema);
    QVERIFY(ts1.isValid());
    TableStructure ts2("classes");
    ts2.addField("En", SQLType::Text());
    ts2.addField("De", SQLType::Text());
    ts2.addField("Hu", SQLType::Text());
    ts2.addField("ID", SQLType::DefaultPK());
    QCOMPARE(ts1, ts2);
    QString sql1 = schema.replace(QRegularExpression("\\s+"), "");
    sql1.replace(QRegularExpression("\""), "");
    QString sql2 = ts2.sqlCommand();
    sql2.replace(QRegularExpression("\\s+"), "");
    QCOMPARE(sql1, sql2);
}



