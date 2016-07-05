#ifndef NUMBER_H
#define NUMBER_H

#include <QObject>
#include <QDebug>

class Number : public QObject
{
    Q_OBJECT

public:
    explicit Number(int number, QObject* parent = nullptr);
    int value() const;

private:
    int _number;
};

// Register metatype so it can be used as data in item inputs and outputs.
Q_DECLARE_METATYPE(Number*)

#endif
