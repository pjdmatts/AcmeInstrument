// C++ Cookbook
// By D. Ryan Stephens, Christopher Diggins, Jonathan Turkanis, Jeff Cogswell
// 11.17. Computing the Fast Fourier Transform

#ifndef CALCFFT_H
#define CALCFFT_H

class Calcfft
{
private:
public:
    template <class Iter_T>
    void fft(Iter_T a, Iter_T b, int log2n);
};

#endif