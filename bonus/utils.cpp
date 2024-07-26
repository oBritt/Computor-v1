#include "computor.hpp"

bool isNumb(char c)
{
    return (c >= '0' && c <= '9') ? true : false;
}

bool isDecimal(char c)
{
    return (isNumb(c) || c == '.');
}

double fromStringToDouble(std::string &str)
{
    std::stringstream ss(str);
    double out;
    ss >> out;
    return (out);
}

long long fromStringToInt(std::string &str)
{
    std::stringstream ss(str);
    long long out;
    ss >> out;
    if (str.size() > 10 || out > 2147483647)
    {
        throw std::runtime_error(str);
    }
    return (out);
}

std::string remove_spaces(std::string& str)
{
    std::string out = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
            out.push_back(str[i]);
    }
    return (out);
}

int get_len(std::string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (i != 0 && (str[i] == '+' || str[i] == '-' || str[i] == '='))
            return (i);
    }
    return (str.size());
}

void    change_x(std::string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'x')
            str[i] = 'X';
    }
}

std::string get_chunk(std::string& str)
{
    std::string chunk;
    int         len;

    len = get_len(str);
    chunk = str.substr(0, len);
    str = str.substr(len);
    return (chunk);
}

int get_fist_not_numb(std::string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (!isDecimal(str[i]))
            return (i);
    }
    return (str.size());
}

double myfabs(double value)
{
    if (value >= 0)
        return value;
    return -value;
}

double square_root(double number)
{
    double min = 0;
    double max = number;
    double mid;
    int  i = 0;
    while (min < max)
    {
        if (i == 100000)
            return (min);
        mid = (min + max) / 2.0;
        if (number == mid * mid)
        {
            return (mid);
        }
        else if (number < mid * mid)
        {
            max = mid;
        }
        else
            min = mid;
        i++;
    }
    return (min);
}

double cubic_root(double number)
{
    double factor = number >= 0 ? 1.0 : -1.0;
    number = myfabs(number);
    double min = 0;
    double max = number;
    double mid;
    int  i = 0;
    while (min < max)
    {
        if (i == 100000)
            return (min);
        mid = (min + max) / 2.0;
        if (number == mid * mid * mid)
        {
            return (mid * factor);
        }
        else if (number < mid * mid * mid)
        {
            max = mid;
        }
        else
            min = mid;
        i++;
    }
    return (min * factor);
}



std::string get_imaganery_number(double real, double imag)
{
    std::string out = "";

    std::string reals = NumberToString(myfabs(real));
    std::string image = NumberToString(myfabs(imag));
    if (reals == "0" && image == "0")
    {
        return ("0");
    } 
    if (reals == "0")
    {
        if (imag > 0)
        {
            if (image != "1")
                out += image;
        }
        else
        {
            out += "-";
            if (image != "1")
                out += image;
        }
        out += "i";
    }
    else
    {
        out = reals;
        if (imag > 0)
        {
            out += " + ";
            if (image != "1")
                out += image;
        }
        else
        {
            out += " - ";
            if (image != "1")
                out += image;
        }
        out += "i";
    }
    return (out);
}

std::string get_normal_numb(double coef, int exp, bool first)
{

    std::string out;
    std::string coefi = NumberToString(myfabs(coef));
    bool seen = 0;
    if (coef > 0)
    {
        if (!first)
            out = " + ";
        if (myfabs(coef) != 1.0)
        {
            seen = 1;
            out += coefi;
        }
        else if (myfabs(coef)== 1.0 && exp == 0)
        {
            out += coefi;
        }
    }
    else
    {
        if (first)
        {
            out = "-";
        }
        else
        {
            out = " - ";
        }
        if (myfabs(coef) != 1.0)
        {
            seen = 1;
            out += coefi;
        }
        else if (myfabs(coef)== 1.0 && exp == 0)
        {
            out += coefi;
        }
    }
    if (exp != 0)
    {
        if (seen)
        {
            out += " * ";
        }
        out += "X";
        if (exp != 1)
            out += "^" + NumberToString(exp);
    }
    return out;
}

double my_arccos(double x)
{
    if (x >= 0)
    {
        return PI / 2.0 - square_root(2.0 * (1.0 - x)) * (1.0 + 0.125 * (1.0 - x));
    }
    return PI - my_arccos(-x);
}

double range_pi(double x)
{
    while (x > PI)
    {
        x -= 2.0 * PI;
    }
    while (x < -PI)
    {
        x += 2.0 * PI;
    }
    return x;
}


double my_cos(double x)
{
    x = range_pi(x);
    double result = 1.0;
    double term = 1.0;
    for (int n = 1; n < 10; ++n) {
        term *= -x * x / (2 * n * (2 * n - 1));
        result += term;
    }
    return result;
}

double make_valid(double x)
{
    while (x > 2.0 * PI)
    {
        x -= 2.0 * PI;
    }
    while (x < 0.0)
    {
        x += 2.0 * PI;
    }
    return (x);
}

void    improve_xs(std::string &str)
{
    std::string copy = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'X')
        {
            int len = 0;
            while (i < str.size())
            {
                if (str[i] != 'X')
                {
                    i--;
                    break ;
                }
                len++;
                i++;
            }
            copy.push_back('X');
            if (len != 1)
            {
                copy.push_back('^');
                copy += NumberToString(len);
            }
        }
        else
        {
            copy.push_back(str[i]);
        }
    }
    str = copy;
}