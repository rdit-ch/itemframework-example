#include "number/number_transporter.h"

NumberTransporter::NumberTransporter()
{}

void NumberTransporter::sendNumber(Number number)
{
    emit numberReceived(number);
}
