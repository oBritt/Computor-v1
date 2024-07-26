#include "Solver.hpp"

Solver::Solver(std::string& equation): equation(equation), degree(0)
{

}

double Solver::get_a(std::string& str)
{
    if (str[0] == 'X')
        return (1);
    int len = get_fist_not_numb(str);
    std::string a = str.substr(0, len);
    str = str.substr(len);
    return (fromStringToDouble(a));
}

int Solver::get_exp(std::string& str)
{
    if (str == "")
        return (0);
    if (str[0] == '*')
        str = str.substr(1);
    if (str.size() == 1)
        return (1);
    str = str.substr(2);
    return (fromStringToInt(str));
}


void    Solver::handle_chunk(std::string& str, int factor)
{
    std::string information;

    if (str[0] == '+')
    {
        information = str.substr(1);
    }
    else if (str[0] == '-')
    {
        information = str.substr(1);
        factor *= -1;
    }
    else
        information = str;
    double a = get_a(information);
    int exp = get_exp(information);
    mp[exp] += (factor * a);
    if (mp[exp] == 0.0)
        mp.erase(exp);
}

void    Solver::get_reduced(void)
{
    if (mp.size() == 0)
    {
        this->reduced = "0 = 0";
        return ;
    }
    for (std::map<int, double>::iterator it = this->mp.begin(); it != this->mp.end(); it++)
    {
        this->reduced += get_normal_numb(it->second, it->first, it == this->mp.begin());
        this->degree = it->first;
    }
    this->reduced += " = 0";
}

void    Solver::solve_liniar(void)
{
    double m = this->mp[1];
    double b = this->mp[0];
    this->solution = "The solution is:\n" + NumberToString(-b / m);
}

void    Solver::solve_quadratic(void)
{
    double a = this->mp[2];
    double b = this->mp[1];
    double c = this->mp[0];

    double D = b * b - 4 * a * c;
    if (D > 0)
    {
        this->solution = "Discriminant is strictly positive, the two solutions are:\n";
        D = square_root(D);
        double sol1 = (-b + D) / (2 * a);
        double sol2 = (-b - D) / (2 * a);
        if (sol2 > sol1)
            std::swap(sol1, sol2);
        this->solution += NumberToString(sol1) + "\n";
        this->solution += NumberToString(sol2);
    }
    else if (D == 0)
    {
        this->solution = "Discriminant is zero, the solution is:\n";
        this->solution += NumberToString(-b / (2 * a));
    }
    else
    {
        this->solution = "Discriminant is strictly negative, the imaginary two solutions are:\n";
        D = square_root(-D);
        double real_s1 = -b / (2 * a); 
        double imag_s1 = D / (2 * a);
        double imag_s2 = -D / (2 * a);
        this->solution += get_imaganery_number(real_s1, imag_s1) + "\n";
        this->solution += get_imaganery_number(real_s1, imag_s2);
    }
}

void    Solver::get_solution(void)
{
    if (this->degree == 0)
    {
        if (this->mp[0] == 0)
            this->solution = "Every number is solution for that equation";
        else
            this->solution = "No solution to this equation";
    }
    else if (this->degree == 1)
    {
        solve_liniar();
    }
    else if (this->degree == 2)
    {
        solve_quadratic();
    }
    else
    {
        this->solution = "The polynomial degree is strictly greater than 3, I can't solve.";
    }
}

void    Solver::solve(void)
{
    std::string work_string = this->equation;
    int factor = 1;
    while (work_string.size())
    {
        if (work_string[0] == '=')
        {
            work_string = work_string.substr(1);
            factor = -1;
        }
        std::string currentChunk = get_chunk(work_string);
        handle_chunk(currentChunk, factor);
    }
    get_reduced();
    get_solution();
}

std::ostream& operator<<(std::ostream &o, Solver const &other)
{
    o << "Reduced form: " << other.reduced << std::endl;
    o << "Polynomial degree: " << other.degree << std::endl;
    o << other.solution << std::endl;
    return (o);
}
