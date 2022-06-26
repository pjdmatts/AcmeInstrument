#include "data.h"

void Data::Greeting()
{
    std::cout <<"I am the Data"<<std::endl;
}

std::vector<float> Data::getXData()
{
    return _x_data;
} 

std::vector<float> Data::getYData()
{
    return _y_data;
}    