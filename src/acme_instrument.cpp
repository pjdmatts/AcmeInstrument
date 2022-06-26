#include <iostream>
#include <memory>
#include "instrument.h"
#include "data_in.h"
#include "data.h"
#include "analysis.h"
#include "plotter.h"


int main() {
    
    Instrument instrument = Instrument();
    instrument.InstrumentGreeting();

    //Ask for user input
    instrument.DataInputGreeting();

    //Create a data object from the user input
    DataIn datain = DataIn();
    auto data_ptr = datain.Input();

    //auto data_ptr = instrument.DataInput();

    Plotter plot = Plotter();
    plot.MakePlot(data_ptr);

    //instrument.DataGreeting();

    //Ask the user what kind of analysis they want to do
    //instrument.AnalysisGreeting();

    //Do the Analysis
    //Make the Plot
    //instrument.PlotGreeting();
    //instrument.MakePlot();
    
}