#ifndef IMPORTCOLUMNPROPERTIES_H
#define IMPORTCOLUMNPROPERTIES_H

#include <QWidget>
class QComboBox;

class ColumnPropertiesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ColumnPropertiesWidget(QWidget *parent = 0);

private slots:
    void setType(int idx);

private:
    QComboBox *useAs;
    QComboBox *separator;
    QComboBox *format;
};

#endif // IMPORTCOLUMNPROPERTIES_H