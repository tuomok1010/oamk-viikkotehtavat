#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>

class Pankkitili
{
    public:
    Pankkitili(std::string omistaja);
    virtual ~Pankkitili();

    double get_balance() const;
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);

    protected:
    std::string omistaja;
    double saldo;

    private:
};

#endif // PANKKITILI_H
