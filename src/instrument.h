#ifndef INSTRUMENT_H
#define INSTRUMENT_H


#include <iostream>
#include "data_in.h"
#include "analysis.h"
#include "plotter.h"




class Instrument
{
    public:
    void InstrumentGreeting();
    void DataGreeting() {data.Greeting();}
    void AnalysisGreeting() {analysis.Greeting();}
    void PlotGreeting() {plot.Greeting();}

    private:
    DataIn data;
    Analysis analysis;
    Plotter plot;
};

#endif

