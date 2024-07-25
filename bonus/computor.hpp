

#ifndef COMPUTOR_HPP
#define COMPUTOR_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Solver.hpp"
#include <stdio.h>

class Solver;

std::string remove_spaces(std::string& str);
std::string get_chunk(std::string& str);
int get_fist_not_numb(std::string& str);
double fromStringToDouble(std::string &str);
int fromStringToInt(std::string &str);
double square_root(double number);
std::string get_imaganery_number(double real, double imag);
bool    check_syntax(std::string& str);

template <typename T>
std::string NumberToString(const T numb) {
    std::stringstream ss;
    ss << numb;  
    return ss.str();
}

#endif