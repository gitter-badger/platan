// This file is part of Platan.
// Copyright (C) 2014 Gábor Angyal
//
// Platan is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Platan is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Platan.  If not, see <http://www.gnu.org/licenses/>.

#ifndef SQLITEDB_H
#define SQLITEDB_H

#include <string>
#include <QString>
#include <exception>
#include "sqlite3.h"
#include <QDate>
#include "sqlitestatement.h"
#include "sqlquery.h"
#include "sqlselect.h"

class db_exception : public std::exception
{
public:
    db_exception(){}
};


class SQLiteDB
{
public:
    void SetPath(std::string data_base_path);
    void Open();
    void Close();
    void BeginTransaction();
    void EndTransaction();
    void Execute(SQLQuery &query);
    void Finalize(SQLiteStatement &statement);
    bool Step(SQLiteStatement &statement);
    void Prepare(SQLiteStatement &statement, SQLSelect &select);
protected:
    sqlite3 *db;
    std::string data_base_path;
};

#endif // SQLITEDB_H
