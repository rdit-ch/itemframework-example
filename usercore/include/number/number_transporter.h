#ifndef NUMBER_TRANSPORTER_H
#define NUMBER_TRANSPORTER_H

#include <QObject>
#include "appcore.h"
#include "number/number.h"

class CORE_EXPORT NumberTransporter : public QObject
{
    Q_OBJECT

public:
    explicit NumberTransporter();

signals:
    void numberReceived(Number number);

public slots:
    void sendNumber(Number number);
};

// Register type so it can be used as data in item inputs and outputs.
Q_DECLARE_METATYPE(NumberTransporter*)

#endif // NUMBER_TRANSPORTER_H
