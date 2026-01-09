#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(std::string nimi) : next(nullptr), nimi(nimi)
{
    std::cout << "Luodaan seuraaja " << nimi << std::endl;
}

std::string Seuraaja::get_nimi() const
{
    return nimi;
}

void Seuraaja::paivitys(std::string viesti)
{
    std::cout
        << "Seuraaja " << nimi
        << " sai viestin " << viesti
        << std::endl;
}
