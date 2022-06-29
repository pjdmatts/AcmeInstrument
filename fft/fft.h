#ifndef FOURIER_H
#define FOURIER_H


template <class Iter_T> class Fourier
{
    public:
    void fft(Iter_T a, Iter_T b, int log2n);
    void do_fft();
};
#endif