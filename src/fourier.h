#ifndef FOURIER_H
#define FOURIER_H

#include <iostream>
#include <complex>
#include <cmath>
#include <iterator>
#include "fftHelper.h"
#include "calc_fft.h"
#include "calc_fft.cpp"
#include "data.h"

class Fourier 
{
    public:
    std::shared_ptr<Data> perform_fft(std::shared_ptr<Data> input_data);
};

#endif