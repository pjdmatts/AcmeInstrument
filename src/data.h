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
    void setXData(std::vector<double> x_data) {_x_data = x_data;};
    void setYData(std::vector<double> y_data) {_y_data = y_data;};
    std::vector<double> getXData();
    std::vector<double> getYData();

    // behavior methods
    void Greeting();
    void printXData();
    void printYData();

private:
    std::vector<double> _x_data;
    std::vector<double> _y_data;
};

#endif