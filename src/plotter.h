#ifndef PLOTTER_H
#define PLOTTER_H


#include <iostream>
#include "data.h"

class Plotter
{
    public:
    void MakePlot(std::shared_ptr<Data> plot_data);
    void Greeting();
};

#endif