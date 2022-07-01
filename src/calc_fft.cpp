// C++ Cookbook
// By D. Ryan Stephens, Christopher Diggins, Jonathan Turkanis, Jeff Cogswell
// 11.17. Computing the Fast Fourier Transform

#include <iostream>
#include <complex>
#include <cmath>
#include <iterator>
#include "fftHelper.h"
#include "calc_fft.h"

using namespace std;

const double PI = 3.1415926536;

template <class Iter_T>
void Calcfft::fft(Iter_T a, Iter_T b, int log2n)
{
  typedef typename iterator_traits<Iter_T>::value_type complex;
  fftHelper helper = fftHelper();
  const complex J(0, 1);
  int n = 1 << log2n;
  for (unsigned int i = 0; i < n; ++i)
  {
    unsigned int n = helper.bitReverse(i, log2n);
    b[n] = a[i];
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