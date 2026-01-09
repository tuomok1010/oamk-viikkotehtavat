#include "luottotili.h"

Luottotili::Luottotili(std::string omistaja, double luottoraja) :
    Pankkitili(omistaja),
    luottoraja(luottoraja)
{

}

Luottotili::~Luottotili()
{

}

bool Luottotili::deposit(double summa)
{
    if(summa <= 0)
        return false;

    if(saldo + summa > 0)
        return false;

    saldo += summa;
    return true;
}

bool Luottotili::withdraw(double summa)
{
    if(summa <= 0)
        return false;

    if(saldo - summa < (0-luottoraja))
        return false;

    saldo -= summa;
    return true;
}
