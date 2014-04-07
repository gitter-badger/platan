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

#include "sqltype.h"


SQLType SQLType::Invalid(-1);
SQLType SQLType::Integer(0);
SQLType SQLType::Real(1);
SQLType SQLType::Text(2);
SQLType SQLType::Numeric(3);

SQLType::SQLType(char val)
    :val(val), isPK(false), isAutoIncrement(false), isNotNull(false)
{

}

SQLType::SQLType(SQLType other, bool isPK, bool isAutoIncrement, bool isNotNull)
    :val(other.val), isPK(isPK), isAutoIncrement(isAutoIncrement), isNotNull(isNotNull)
{

}

SQLType SQLType::PK() const
{
    return SQLType(*this, true, isAutoIncrement, isNotNull);
}

SQLType SQLType::AutoIncrement() const
{
    return SQLType(*this, isPK, true, isNotNull);
}

SQLType SQLType::NotNull() const
{
    return SQLType(*this, isPK, isAutoIncrement, true);
}

bool SQLType::operator ==(const SQLType& other) const
{
  return val == other.val &&
         isPK == other.isPK &&
         isAutoIncrement == other.isAutoIncrement &&
          isNotNull == other.isNotNull;
}

bool SQLType::operator !=(const SQLType &other) const
{
    return !(*this == other);
}

QString SQLType::toString() const
{
    QString result;
    switch (val) {
    case 0:
        result = "INTEGER";
        break;
    case 1:
        result = "REAL";
        break;
    case 2:
        result = "TEXT";
        break;
    case 3:
        result = "NUMERIC";
        break;
    }
    if (isPK)
        result += " PRIMARY KEY";
    if (isAutoIncrement)
        result += " AUTOINCREMENT";
    if (isNotNull)
        result += " NOT NULL";
    return result;
}

SQLType SQLType::parse(QString sqlstring)
{

    SQLType result = Invalid;
    if (sqlstring.startsWith("INTEGER"))
        result = Integer;
    else if (sqlstring.startsWith("REAL"))
        result = Real;
    else if (sqlstring.startsWith("TEXT"))
        result = Text;
    else if (sqlstring.startsWith("NUMERIC"))
        result = Numeric;
    else
        return Invalid;

    if (sqlstring.contains("PRIMARY KEY"))
        result = result.PK();

    if (sqlstring.contains("AUTOINCREMENT"))
        result = result.AutoIncrement();

    if (sqlstring.contains("NOT NULL"))
        result = result.NotNull();

    return result;
}

