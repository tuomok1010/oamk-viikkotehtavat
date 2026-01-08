#ifndef CHEF_H
#define CHEF_H

#include <string>

class Chef
{
    public:
    Chef(std::string name);
    ~Chef();

    inline std::string get_name() const { return chef_name; }

    int make_salad(int num_ingredients);
    int make_soup(int num_ingredients);

    protected:
    std::string chef_name;
};

#endif // CHEF_H
