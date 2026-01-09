#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <string>

class Seuraaja
{
    public:
    Seuraaja(std::string nimi);
    std::string get_nimi() const;
    void paivitys(std::string viesti);

    Seuraaja* next;

    private:
    std::string nimi;
};

#endif // SEURAAJA_H
