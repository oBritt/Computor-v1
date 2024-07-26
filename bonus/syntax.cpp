
#include "computor.hpp"

bool isAllowed(char c)
{
    if ((c >= '0' && c <= '9') || c == 'X' || c == '.' || c == '^' || c == '+' || c == '-' || c == '=' || c == '*')
        return (true);
    return (false);
}

bool checkChars(std::string& str)
{
    for(int i = 0; i < str.size(); i++)
    {
        if (!isAllowed(str[i]))
        {
            std::cout << "'" << str[i] << "' is not allowed char" << std::endl;
            return false;
        }
    }
    return (true);
}

bool    checkStuff(std::string& str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (i != 0 && (str[i] == '+' || str[i] == '-' || str[i] == '=') && (str[i - 1] == '-' || str[i - 1] == '+'))
        {
            std::cout << "two operators '+' and '-' cant follow each other and '+' or '-' cant be before '='" << std::endl;
            return (false);
        }
        if (str[i] == '*')
        {
            std::cout << "'*' has wrong position" << std::endl;
            return false;
        }
        if (str[i] == '^')
        {
            std::cout << "'^' must be after 'X'" << std::endl;
            return false;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            while (i < str.size())
            {
                if (str[i] == 'X' || str[i] == '+' || str[i] == '-' || str[i] == '=')
                    break ;
                if (str[i] == '^')
                {
                    std::cout << "'" << str[i] << "' cant be after int" << std::endl;
                    return (false); 
                }
                if (str[i] == '*')
                {
                    i++;
                    while (i < str.size())
                    {
                        if (str[i] != 'X')
                        {
                            std::cout << "unexpected token after '*'" << std::endl;
                            return (false);
                        }
                        else
                            break;

                        i++;
                    }
                    if (i == str.size())
                        return (true);
                    break ;
                }
                i++;
            }
        }
        if (i == str.size())
            return true;
        if (str[i] == 'X')
        {
            i++;
            if (i == str.size())
                return true;
            if (str[i] == '^')
            {
                i++;
                if (!(str[i] >= '0' && str[i] <= '9'))
                {
                    std::cout << "'" << str[i] << "' is not allowed after '^' expected int" << std::endl;
                    return (false);
                }
                while (i < str.size())
                {
                    if (str[i] == '=' || str[i] == '+' || str[i] == '-')
                        break ;
                    if (str[i] == '*' || str[i] == '^' || str[i] == '.' || str[i] == 'X')
                    {
                        std::cout << "'" << str[i] << "' is not allowed excpected is int or operator" << std::endl;
                        return (false);
                    }
                    i++;   
                }
            }
            else if (str[i] == 'X')
            {
                std::cout << "'" << str[i] << "' is not allowed after X" << std::endl;
                return (false);
            }
            else
            {
                if (!(str[i] == '=' || str[i] == '-' || str[i] == '+'))
                {
                    std::cout << "wrong token after 'X' expected operators" << std::endl;
                    return (false);
                }
            }

        }
    }
    return (true);
}

bool    check_syntax(std::string& str)
{
    change_x(str);
    improve_xs(str);
    if (str.find('=') == std::string::npos)
    {
        std::cout << "there must be '=' sign" << std::endl;
        return (false);
    }
    if (std::count(str.begin(), str.end(), '=') != 1)
    {
        std::cout << "there must be only 1 '=' sign" << std::endl;
        return false;
    }
    if(str[0] == '=' || str.back() == '=')
    {
        std::cout << "'=' sign cant be in the begining or end" << std::endl;
        return false;
    }
    if (str.back() == '*')
    {
        std::cout << "'*' cant be at the end" << std::endl;
        return (false);
    }
    if (!checkChars(str))
        return false;
    if (!checkStuff(str))
        return false;
    return true;
}