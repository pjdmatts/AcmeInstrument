#include <iostream>
#include "data.h"

void Data::Greeting()
{
    std::cout << "I am the Data" << std::endl;
}

std::vector<double> Data::getXData()
{
    return _x_data;
}

std::vector<double> Data::getYData()
{
    return _y_data;
}

void Data::printXData()
{
    for(auto i : _x_data) std::cout << i << std::endl;
}

void Data::printYData()
{
    for(auto i : _y_data) std::cout << i << std::endl;
}