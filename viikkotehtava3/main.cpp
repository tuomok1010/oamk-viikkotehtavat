#include <iostream>

#include "italianchef.h"

int main()
{
    Chef chef("Gordon");
    const int chef_n_salad_ingredients = 11;
    const int chef_n_soup_ingredients = 14;

    chef.make_salad(chef_n_salad_ingredients);
    chef.make_soup(chef_n_soup_ingredients);

    ItalianChef italian_chef("Luigi");
    const int italian_chef_n_salad_ingredients = 9;
    const int italian_chef_n_flour = 12;
    const int italian_chef_n_water = 12;

    italian_chef.make_salad(italian_chef_n_salad_ingredients);

    std::string password = "test wrong pass";
    italian_chef.ask_secret(password, italian_chef_n_flour, italian_chef_n_water);

    password = "pizza";
    italian_chef.ask_secret(password, italian_chef_n_flour, italian_chef_n_water);


    return 0;
}
