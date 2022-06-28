#include <iostream>
#include <memory>
#include <vector>
#include "instrument.h"
#include "data_in.h"
#include "data.h"
#include "analysis.h"
#include "plotter.h"
#include "plotter2.h"


int main() {
    
    Instrument instrument = Instrument();
    instrument.InstrumentGreeting();

    //Ask for user input
    //instrument.DataInputGreeting();

    //Create a data object from the user input
    DataIn datain = DataIn();
    datain.Greeting();
    auto data_ptr = datain.Input();
    //std::cout << "Testing Data" << std::endl;
    //data_ptr->printXData();
    
    //auto data_ptr = instrument.DataInput();

    Plotter2 plot = Plotter2();
    plot.MakePlot();

    //instrument.DataGreeting();

    //Ask the user what kind of analysis they want to do
    //instrument.AnalysisGreeting();

    //Do the Analysis
    //Make the Plot
    //instrument.PlotGreeting();
    //instrument.MakePlot();
    
}