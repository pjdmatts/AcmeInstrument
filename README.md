# AcmeInstrument

## Purpose

AcmeInstrument is the beginning of a general software 'instrument' that allows the user to analyze data.

Currently the tool is set up to analyze data in two column .csv format.

Two forms of analysis are provided:

- Select option `0` for a passthrough that allows the user to view the data before any math is done on it.
- Select option `1` for a plot of the Fast Fourier Transform of the data, allowing the user to identify the frequency content of the data.

## Plotting

AcmeInstrument currently uses `Gnuplot` to create plots from the `Plotter` class.

## Compiling and Testing 

Install GnuPlot:

`sudo apt install gnuplot`

Clone this repo:

`git clone https://github.com/pjdmatts/AcmeInstrument.git`

Build with CMAKE:

`mkdir build`

`cd build`

`cmake ..&&make`

## Example

Example data is provided in the `data` folder. It includes `foo4.csv` which is a cosine wave at 30Hz sample at 960Hz.

Here is how you would used the tool to identify the frequency content of this wave:
```
$ ./AcmeInstrument
Welcome to ACME Instrument
I can take a two column csv file as an input
Please Provide the path to the file you would like to analyze
../data/foo4.csv
You entered ../data/foo4.csv
The file stream has been created!
Now we do Analysis on the data.
How should we analyze the data: 
Enter 0 for a passthrough to view the data
And enter 1 for an FFT of the data
1
You selected to do Fast Fourier Transform
What is the size N of the subset you want to analyze, to the nearest power of 2?
512
What rate, in Hz, was your data sampled at?
960
Setting frequency bin size to 1.875Hz
Opening gnuplot... succeded.
```

## Loops, Functions, I/O

This project reads from an input file and gets input from the user about what functions to perform and the nature of the data inputted (in order to correclty perform the Fast Fourier Transform)

Plotting relies in Gnuplot, and we use the header only solution provided at https://github.com/martinruenz/gnuplot-cpp

This approach relies on pipes to interface with Gnuplot and we choose to send files to these pipes - as an interim step new csv files are written and sent to Gnuplot

Within classes (see below) functionality is split into seperate functions.

## Object Oriented Programming

Class interfaces are declared in .h files and implemented in .cpp files

`acme_instrument.cpp` contains `main()` and creates instances of the following classes:

- The class `Instrument` is the starting point for interaction with the user and welcomes the user to the tool. Currently `Instrument` uses composition to include functionality from `DataIn`. 

- The class `DataIn` sets up a shared pointer to a `Data` object that is used to move data around the tool. This object asks the user for file input.

- `Analysis` presents the user with their choices as to what to do with the file input.

- within `Analysis` we find instances of `Plotter`, which handles sending files to Gnuplot for plotting, and `Fourier` which handles performing FFT on the data.

- `Fourier` relies on a template within `Calcfft` that runs FFT on an iterable input - this approach is based on the example in ***C++ Cookbook, Ryan Stephens, Christopher Diggins, Jonathan Turkanis, Jeff Cogswell, Section 11.17.Computing the Fast Fourier Transform***

## Memory Management

- This project relies on smart pointers, see for example `DataIn`, which creates a shared pointer to an object of class `Data`