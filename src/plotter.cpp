#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "gnuplot.h"
#include "plotter.h"
#include "data.h"

std::string Plotter::MakeFile(std::shared_ptr<Data> plot_data)
{
    /**need to get the contents of plot_data and make a csv file**/
    std::string filename = "plot.csv";
    std::ofstream myFile(filename);
    std::vector<double> x = plot_data->getXData();
    std::vector<double> y = plot_data->getYData();
    for (int i = 0; i < x.size(); ++i)
    {
        myFile << x.at(i) << "," << y.at(i) << "\n";
    }
    myFile.close();
    return filename;
}

void Plotter::MakePlot(std::string input_file)
{
    /**Simplified Plotter**/
    std::string begin = "plot \"";
    std::string end = "\" with lines";
    std::string command = begin + input_file + end;
    GnuplotPipe gp;
    gp.sendLine("set datafile separator \',\'");
    gp.sendLine(command);
}

void Plotter::Greeting()
{
    std::cout << "I am doing Plotting Things Now" << std::endl;
}