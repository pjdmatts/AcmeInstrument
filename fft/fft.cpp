#include <iostream> /* printf */
#include <math.h>   /* sin */
#include <vector>
#include <fstream>
#include <complex>
#include <cmath>
#include <iterator>
#include "fft.h"
#include "fft_helper.h"

template <class Iter_T>
void Fourier<Iter_T>::fft(Iter_T a, Iter_T b, int log2n)
{
    typedef typename iterator_traits<Iter_T>::value_type complex;
    const complex J(0, 1);
    int n = 1 << log2n;
    Helper helper = Helper();
    for (unsigned int i = 0; i < n; ++i)
    {
        b[helper.bitReverse(i, log2n)] = a[i];
    }
    for (int s = 1; s <= log2n; ++s)
    {
        int m = 1 << s;
        int m2 = m >> 1;
        complex w(1, 0);
        complex wm = exp(-J * (PI / m2));
        for (int j = 0; j < m2; ++j)
        {
            for (int k = j; k < n; k += m)
            {
                complex t = w * b[k + m2];
                complex u = b[k];
                b[k] = u + t;
                b[k + m2] = u - t;
            }
            w *= wm;
        }
    }
}

