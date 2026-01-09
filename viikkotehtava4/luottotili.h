#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "pankkitili.h"

class Luottotili : public Pankkitili
{
    public:
    Luottotili(std::string omistaja, double luottoraja);
    ~Luottotili();

    bool deposit(double summa) override;
    bool withdraw(double summa) override;

    protected:
    double luottoraja;

    private:
};

#endif // LUOTTOTILI_H
