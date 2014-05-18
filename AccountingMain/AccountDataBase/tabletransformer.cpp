#include "tabletransformer.h"
#include <statementtablemodel.h>
#include <csvtablemodel.h>
#include <vector>
#include <QVector>

TableTransformer::TableTransformer()
{
    transformations.push_back(&Amount);
    transformations.push_back(&Type);
    transformations.push_back(&Date);
    transformations.push_back(&Payee);
    transformations.push_back(&PayeeAccount);
    transformations.push_back(&Description);
}

StatementTableModel *TableTransformer::transform(QAbstractTableModel *model) const
{
    std::vector<StatementRow> rows;
    for(int r = 0; r < model->rowCount(); ++r)
    {
        StatementRow row;
        row.Ammount = Amount.apply(model, r);
        row.Type = Type.apply(model, r);
        row.Date = Date.apply(model, r);
        row.Payee = Payee.apply(model, r);
        row.PayeeAccount = PayeeAccount.apply(model, r);
        row.Description = Description.apply(model, r);
        rows.push_back(row);
    }
    return new StatementTableModel(rows);
}

void TableTransformer::removeColumnType(int column)
{
    for (TransformationBase *tr : transformations)
    {
        if (tr->getColumn() == column)
        {
            tr->setColumn(-1);
            break;
        }
    }
}

ColumnType TableTransformer::getColumnType(int column)
{
    int idx = 0;
    for (TransformationBase *tr : transformations)
    {
        if (tr->getColumn() == column)
            return (ColumnType)idx;
        ++idx;
    }
    return ColumnType::None;
}

void TableTransformer::setColumnType(int column, ColumnType type)
{
    removeColumnType(column);
    if (type != ColumnType::None)
        transformations[(int)type]->setColumn(column);
}