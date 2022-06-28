#include <string>
#include "plotter2.h"

void Plotter2::MakePlot(){
    GnuplotPipe gp;
    const std::string text = "..\\fft\\";
    const std::string filename = "abs.csv";
    const std::string input = text + filename;

    gp.sendLine("set datafile separator \',\'");
    gp.sendLine("plot \'" + input + "\' with lines");
}