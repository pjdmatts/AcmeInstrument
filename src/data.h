#ifndef DATA__H
#define DATA__H

#include <iostream>
#include <vector>
#include <memory>

class Data
{
public:
    // Constructor/destructor
    // Data();

    // getters/setters
    void setXData(std::vector<float> x_data) {_x_data = x_data;};
    void setYData(std::vector<float> y_data) {_y_data = y_data;};

    // behavior methods
    void Greeting();
    

private:
    std::vector<float> _x_data;
    std::vector<float> _y_data;
};

#endif