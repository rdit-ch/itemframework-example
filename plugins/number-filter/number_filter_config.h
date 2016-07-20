#ifndef NUMBER_FILTER_CONFIG_H
#define NUMBER_FILTER_CONFIG_H

#include <QObject>

class NumberFilterConfig
{
    // Properties of Q_GADGET and Q_OBJECT classes are serialized and deserialized
    // automatically.
    // Alternatively, custom serializers and deserializers can be registered, in
    // which case the following two lines can be removed. For an example of this,
    // see the uncommented lines in the NumberFilterFactory
    Q_GADGET
    Q_PROPERTY(int modulus READ modulus WRITE setModulus USER true)

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
