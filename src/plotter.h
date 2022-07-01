#ifndef PLOTTER_H
#define PLOTTER_H

#include <iostream>
#include <string>
#include "data.h"

class Plotter
{
public:
    std::string MakeFile(std::shared_ptr<Data> plot_data);
    void MakePlot(std::string file);
    void Greeting();

};

#endif