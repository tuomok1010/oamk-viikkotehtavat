#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include <string>

class Seuraaja;

class Notifikaattori
{
    public:
    Notifikaattori();

    void lisaa(Seuraaja* seuraaja);
    void poista(Seuraaja* seuraaja);
    void tulosta();
    void postita(std::string viesti);

    private:
    Seuraaja* seuraajat;
};

#endif // NOTIFIKAATTORI_H
