// C++ Cookbook
// By D. Ryan Stephens, Christopher Diggins, Jonathan Turkanis, Jeff Cogswell
// 11.17. Computing the Fast Fourier Transform

#ifndef HELPER_H
#define HELPER_H

class fftHelper
{
private:
    /* data */
public:
    unsigned int bitReverse(unsigned int x, int log2n);
};

#endif