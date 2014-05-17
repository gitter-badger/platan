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

#ifndef STATEMENTEXTRACTTABLEMODEL_H
#define STATEMENTEXTRACTTABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include "statementextractrow.h"

class StatementExtractTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit StatementExtractTableModel(std::vector<StatementExtractRow> rows, QObject *parent = 0);
    int rowCount(const QModelIndex& parent) const;
    int rowCount() const;
    int columnCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
protected:
    std::vector<StatementExtractRow> Rows;
};

#endif // STATEMENTEXTRACTTABLEMODEL_H