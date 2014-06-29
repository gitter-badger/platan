#ifndef COUNTRYMAPPER_H
#define COUNTRYMAPPER_H

class Country;
template <typename T>
class QVector;
class SQLiteDB;

class CountryMapper
{
public:
    CountryMapper(SQLiteDB &db) : data_base(db)
    {

    }

    QVector<Country> getAll();

private:
    SQLiteDB &data_base;
};

#endif // COUNTRYMAPPER_H
