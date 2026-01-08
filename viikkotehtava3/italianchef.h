#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"

class ItalianChef : public Chef
{
    public:
    ItalianChef(std::string name);
    ~ItalianChef();

    bool ask_secret(std::string user_input, int flour, int water);

    private:
    int make_pizza(int flour, int water);

    const std::string password = "pizza";
    int flour;
    int water;
};

#endif // ITALIANCHEF_H
