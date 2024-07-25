
#include "computor.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage [./executable] [equation]" << std::endl; 
        return (1);
    }
    else
    {
        std::string to_solve = av[1];
        to_solve = remove_spaces(to_solve);
        if (!check_syntax(to_solve))
            return (1);
        Solver s(to_solve);
        s.solve();
        std::cout << s;
    }
}