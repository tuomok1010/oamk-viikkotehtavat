#include "italianchef.h"

#include <iostream>

ItalianChef::ItalianChef(std::string name) : Chef(name)
{
    std::cout
        << "[ItalianChef]: ItalianChef::ItalianChef("
        << name << ") called" << std::endl;
}

ItalianChef::~ItalianChef()
{
    std::cout << "[ItalianChef]: ItalianChef::~ItalianChef()"
              << " called" << std::endl;
}

bool ItalianChef::ask_secret(std::string user_input, int flour, int water)
{
    if(user_input.compare(password) == 0)
    {
        int num_portions = make_pizza(flour, water);

        std::cout
            << "ItalianChef " << get_name() << " with "
            << flour << " flour and "
            << water << " water can make "
            << num_portions << " pizzas. " << std::endl;

        return true;
    }

    return false;
}

int ItalianChef::make_pizza(int flour, int water)
{
    int pizza_count_flour = flour / 5;
    int pizza_count_water = water / 5;

    if(pizza_count_flour < pizza_count_water)
        return pizza_count_flour;
    else
        return pizza_count_water;
}
