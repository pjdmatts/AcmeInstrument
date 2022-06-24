#include <iostream>
#include "instrument.h"
#include "data_in.h"
#include "analysis.h"
#include "plotter.h"


int main() {
    Instrument instrument = Instrument();
    instrument.InstrumentGreeting();
    instrument.DataGreeting();
    instrument.AnalysisGreeting();
    instrument.PlotGreeting();
}