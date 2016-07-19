#ifndef NUMBER_FILTER_CONFIG_H
#define NUMBER_FILTER_CONFIG_H

#include <QObject>

class NumberFilterConfig
{
public:
    int modulus() const;
    void setModulus(int modulus);

    bool operator==(NumberFilterConfig const& other) const;
    bool operator!=(NumberFilterConfig const& other) const;

private:
    int _modulus = 1;
};

Q_DECLARE_METATYPE(NumberFilterConfig)

#endif // NUMBER_FILTER_CONFIG_H
