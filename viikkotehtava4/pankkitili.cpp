#include "pankkitili.h"

Pankkitili::Pankkitili(std::string omistaja) :
    omistaja(omistaja),
    saldo(0.0f)
{

}

Pankkitili::~Pankkitili()
{

}

double Pankkitili::get_balance() const
{
    return saldo;
}

bool Pankkitili::deposit(double summa)
{
    if(summa <= 0)
        return false;

    saldo += summa;
    return true;
}

bool Pankkitili::withdraw(double summa)
{
    if(summa <= 0)
        return false;

    if(saldo - summa < 0)
        return false;

    saldo -= summa;
    return true;
}
