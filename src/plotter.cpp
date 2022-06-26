#include "plotter.h"
#include "data.h"
#include <cmath>
#include <matplot/matplot.h>

void Plotter::MakePlot(std::shared_ptr<Data> plot_data)
{
    using namespace matplot;
    //std::vector<double> x = linspace(0, 2 * pi);
    //std::vector<double> y = transform(x, [](auto x) { return sin(x); });
    std::vector<double> x = plot_data->getXData();
    std::vector<double> y = plot_data->getYData();
    plot(x, y, "-o");
    show();
}

void Plotter::Greeting()
{
    std::cout <<"I am doing Plotting Things Now"<<std::endl;
}