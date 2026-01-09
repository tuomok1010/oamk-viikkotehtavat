#include "asiakas.h"
#include <iostream>


int main()
{
    Asiakas ismo("Ismo", 5000);
    Asiakas tanja("Tanja", 10000);

    if(ismo.talletus(100))
    {
        std::cout << "ismo talletti 100 pankkitililleen" << std::endl;
        ismo.show_saldo();
        std::cout << "----------" << std::endl;
    }


    if(tanja.talletus(1000))
    {
        std::cout << "tanja talletti 1000 pankkitililleen" << std::endl;
        tanja.show_saldo();
            std::cout << "----------" << std::endl;
    }

    if(ismo.nosto(100))
    {
        std::cout << "ismo nosti 100 pankkitililtaan" << std::endl;
        ismo.show_saldo();
        std::cout << "----------" << std::endl;
    }

    if(tanja.tilisiirto(200, ismo))
    {
        std::cout << "tanja siirsi 200 ismolle" << std::endl;
        ismo.show_saldo();
        tanja.show_saldo();
        std::cout << "----------" << std::endl;
    }

    if(ismo.luoton_nosto(4500))
    {
        std::cout << "ismo otti 4500 velkaa" << std::endl;
        ismo.show_saldo();
        std::cout << "----------" << std::endl;
    }

    if(!ismo.luoton_nosto(1000))
    {
        std::cout << "ismo yritti ottaa 1000 lisaa velkaa, mutta eipas annettu!" << std::endl;
        ismo.show_saldo();
        std::cout << "----------" << std::endl;
    }

    return 0;
}
