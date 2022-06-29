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
    analysis.Switch(choice, data_ptr);
}