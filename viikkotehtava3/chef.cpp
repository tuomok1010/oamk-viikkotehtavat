#include "chef.h"

#include <iostream>

Chef::Chef(std::string name) :
    chef_name(name)
{
    std::cout << "[Chef]: Chef::Chef(" << name << ") called" << std::endl;
}

Chef::~Chef()
{
    std::cout << "[Chef]: Chef::~Chef()" << " called" << std::endl;
}

int Chef::make_salad(int num_ingredients)
{
    int num_portions = num_ingredients / 5;

    std::cout
        << "Chef " << get_name() << " with "
        << num_ingredients << " salad ingredients can make "
        << num_portions << " salads." << std::endl;

    return num_portions;
}

int Chef::make_soup(int num_ingredients)
{
    int num_portions = num_ingredients / 3;

    std::cout
        << "Chef " << get_name() << " with "
        << num_ingredients << " soup ingredients can make "
        << num_portions << " soups." << std::endl;

    return num_portions;
}
