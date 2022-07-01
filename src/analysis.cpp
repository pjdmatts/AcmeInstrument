#include<ios>       // for <streamsize>
#include<limits>    // for numeric_limits
#include <chrono>
#include <thread>
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return a;
}

void Analysis::Switch(int a, std::shared_ptr<Data> plot_data)
{
    if (a == 0)
    {
        std::cout << "You selected to Pass Right Through" << std::endl;
        Plotter plot = Plotter();
        std::string passtrhough_file = plot.MakeFile(plot_data);
        plot.MakePlot(passtrhough_file);
    }
    else if (a == 1)
    {
        std::cout << "You selected to do Fast Fourier Transform" << std::endl;
    }
    else
    {
        std::cout << "I am not sure what you need" << std::endl;
    }
}
