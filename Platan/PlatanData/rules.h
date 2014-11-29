#ifndef RULES_H
#define RULES_H

#include <QVector>
#include <QObject>

#include <memory>

#include <rulemapper.h>


class Rule;
class QStringList;

class Rules : public QObject, public QVector<std::shared_ptr<Rule> >
{
    Q_OBJECT
public:
    Rules(SQLiteDB &db);
    void insertRule(Rule rule);
    QVector<Rule> getRules();
    void init();
    void insertRules(QVector<Rule> rules);
    void removeRuleAt(int index);
    void save();
    static QStringList typeList();
    bool changed() const;
signals:
    void dataChanged();
private:
    RuleMapper ruleMapper;
    QVector<std::shared_ptr<Rule> > deletedRules;
    QVector<std::shared_ptr<Rule> > changedRules;
    QVector<std::shared_ptr<Rule> > newRules;
};

#endif // RULES_H
