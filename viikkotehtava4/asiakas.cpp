#include "asiakas.h"
#include <iostream>

Asiakas::Asiakas(std::string nimi, double luottoraja) :
    nimi(nimi),
    pankkitili(Pankkitili(nimi)),
    luottotili(Luottotili(nimi, luottoraja))
{

}

std::string Asiakas::get_nimi() const
{
    return nimi;
}

void Asiakas::show_saldo() const
{
    std::cout
        << "[" << nimi << "] Pankkitili saldo: " << pankkitili.get_balance() << "\n"
        << "[" << nimi << "] Luottotili saldo: " << luottotili.get_balance() << std::endl;
}

bool Asiakas::talletus(double summa)
{
    return pankkitili.deposit(summa);
}

bool Asiakas::nosto(double summa)
{
    return pankkitili.withdraw(summa);
}

bool Asiakas::luoton_maksu(double summa)
{
    return luottotili.deposit(summa);
}

bool Asiakas::luoton_nosto(double summa)
{
    return luottotili.withdraw(summa);
}

bool Asiakas::tilisiirto(double summa, Asiakas& vastaanottaja)
{
    if(nosto(summa))
        return vastaanottaja.talletus(summa);

    return false;
}
