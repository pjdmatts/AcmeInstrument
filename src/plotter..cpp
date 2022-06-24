#include "plotter.h"
#include <cmath>
#include <matplot/matplot.h>

void Plotter::MakePlot()
{
    using namespace matplot;
    std::vector<double> x = linspace(0, 2 * pi);
    std::vector<double> y = transform(x, [](auto x) { return sin(x); });
    plot(x, y, "-o");
    show();
}

void Plotter::Greeting()
{
    std::cout <<"I am doing Plotting Things Now"<<std::endl;
}