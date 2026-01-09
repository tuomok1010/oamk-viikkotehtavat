#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "luottotili.h"

class Asiakas
{
    public:
    Asiakas(std::string nimi, double luottoraja);

    std::string get_nimi() const;
    void show_saldo() const;
    bool talletus(double summa);
    bool nosto(double summa);
    bool luoton_maksu(double summa);
    bool luoton_nosto(double summa);
    bool tilisiirto(double summa, Asiakas& vastaanottaja);

    private:
    std::string nimi;
    Pankkitili pankkitili;
    Luottotili luottotili;
};

#endif // ASIAKAS_H
