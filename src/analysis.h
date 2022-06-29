#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>
#include "data.h"

class Analysis
{
public:
    void Greeting();
    int Choice();
    void Passthrough(std::shared_ptr<Data> plot_data);
};

#endif
