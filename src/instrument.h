#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <iostream>
#include <memory>
#include "data.h"
#include "data_in.h"
#include "analysis.h"
#include "plotter.h"

class Instrument
{
public:
    void InstrumentGreeting();
    void DataInputGreeting() { input.Greeting(); }
    void DataInput() { input.Input(); }
    void DataGreeting() { data.Greeting(); }
    void AnalysisGreeting() { analysis.Greeting(); }
    void PlotGreeting() { plot.Greeting(); }

private:
    DataIn input;
    Data data;
    Analysis analysis;
    Plotter plot;
};

#endif
