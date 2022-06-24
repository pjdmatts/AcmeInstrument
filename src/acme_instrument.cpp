#include <iostream>
#include "instrument.h"
#include "data_in.h"
#include "analysis.h"
#include "plotter.h"


int main() {
    Instrument instrument = Instrument();
    instrument.Greeting();
    //Testing pieces
    DataIn input = DataIn();
    Analysis domath = Analysis();
    Plotter plot = Plotter();
    input.Greeting();
    domath.Greeting();
    plot.Greeting();
    plot.MakePlot();
}