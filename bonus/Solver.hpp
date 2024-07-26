

#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "computor.hpp"

class Solver
{
    public:
        std::string equation;
        std::string reduced;
        std::string solution;
        int         degree;
        std::map<int, double> mp;
        Solver(std::string& equation);
        void solve(void);
        void handle_chunk(std::string& str, int factor);
        double get_a(std::string& str);
        int get_exp(std::string &str);
        void    get_reduced(void);
        void    get_solution(void);
        void solve_liniar(void);
        void   solve_quadratic(void);
        void    solve_cubic(void);
};

std::ostream& operator<<(std::ostream &o, Solver const & other);


#endif