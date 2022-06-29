#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <thread>
#include "instrument.h"
#include "data_in.h"
#include "data.h"
#include "analysis.h"
#include "plotter.h"


int main() {
    
    Instrument instrument = Instrument();
    instrument.InstrumentGreeting();
    DataIn datain = DataIn();
    datain.Greeting();
    auto data_ptr = datain.Input();
    Analysis analysis = Analysis();
    analysis.Greeting();
    int choice;
    choice = analysis.Choice();
    std::cout <<"You chose: " << choice << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    //analysis.Passthrough(data_ptr);
    Plotter plot = Plotter();
    plot.MakePlot(data_ptr);
}