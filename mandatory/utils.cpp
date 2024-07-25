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

int fromStringToInt(std::string &str)
{
    std::stringstream ss(str);
    long long out;
    ss >> out;
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
