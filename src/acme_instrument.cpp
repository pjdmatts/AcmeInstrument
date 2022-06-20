#include <iostream>
#include "instrument.h"
#include "plotter.h"


int main() {
    Instrument instrument = Instrument();
    instrument.Greeting();
    //Testing matplot
    Plotter plot = Plotter();
    plot.MakePlot();
}