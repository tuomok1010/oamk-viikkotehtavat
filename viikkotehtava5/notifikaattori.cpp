#include "notifikaattori.h"
#include "seuraaja.h"
#include <iostream>

Notifikaattori::Notifikaattori() : seuraajat(nullptr)
{
    std::cout << "Luodaan notifikaattori " << std::endl;
}

void Notifikaattori::lisaa(Seuraaja* seuraaja)
{
    Seuraaja* old_first = seuraajat;
    seuraajat = seuraaja;
    seuraaja->next = old_first;
}

void Notifikaattori::poista(Seuraaja* seuraaja)
{
    Seuraaja* s = seuraajat;
    while(s != nullptr)
    {
        if(s->next == seuraaja)
            s->next = seuraaja->next;

        s = s->next;
    }

    std::cout << "Seuraaja " << seuraaja->get_nimi() << " poistettu" << std::endl;
}

void Notifikaattori::tulosta()
{
    Seuraaja* s = seuraajat;
    while(s != nullptr)
    {
        std::cout << s->get_nimi();

        if(s->next != nullptr)
            std::cout << ", ";

        s = s->next;
    }

    std::cout << std::endl;
}

void Notifikaattori::postita(std::string viesti)
{
    std::cout << "Notifikaattori postaa viestin " << viesti << std::endl;

    Seuraaja* s = seuraajat;
    while(s != nullptr)
    {
        s->paivitys(viesti);
        s = s->next;
    }
}
