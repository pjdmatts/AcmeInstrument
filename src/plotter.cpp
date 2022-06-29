#include "plotter.h"
#include "data.h"
#include <cmath>
#include <matplot/matplot.h>

void Plotter::MakePlot(std::shared_ptr<Data> plot_data)
{
    using namespace matplot;
    std::vector<double> x = plot_data->getXData();
    std::vector<double> y = plot_data->getYData();
    plot(x, y);
    show();
}

void Plotter::Greeting()
{
    std::cout <<"I am doing Plotting Things Now"<<std::endl;
}