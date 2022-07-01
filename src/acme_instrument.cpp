#include <iostream>
#include <stdexcept>
#include "instrument.h"
#include "data_in.h"
#include "data.h"
#include "analysis.h"

int main()
{
    Instrument instrument = Instrument();
    DataIn datain = DataIn();
    instrument.InstrumentGreeting();
    instrument.DataInputGreeting();
    auto data_ptr = datain.Input();
    Analysis analysis = Analysis();
    analysis.Greeting();
    int choice;
    choice = analysis.Choice();
    analysis.Switch(choice, data_ptr);
}