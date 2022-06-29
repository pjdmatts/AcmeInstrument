// Figuring out data in
#include "analysis.h"
#include "plotter.h"

void Analysis::Greeting()
{
    std::cout << "Now we do Analysis on the data." << std::endl;
}

int Analysis::Choice()
{
    int a;
    std::cout << "How should we analyze the data: " << std::endl;
    std::cout << "Enter 0 for a passthrough to view the data" << std::endl;
    std::cout << "And enter 1 for an FFT of the data" << std::endl;
    std::cin >> a;
    return a;
}

void Analysis::Passthrough(std::shared_ptr<Data> plot_data)
{
    Plotter plot = Plotter();
    plot.MakePlot(plot_data);
}


