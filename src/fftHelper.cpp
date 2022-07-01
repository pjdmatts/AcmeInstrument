// C++ Cookbook
// By D. Ryan Stephens, Christopher Diggins, Jonathan Turkanis, Jeff Cogswell
// 11.17. Computing the Fast Fourier Transform

#include "fftHelper.h"

unsigned int fftHelper::bitReverse(unsigned int x, int log2n)
{
  int n = 0;
  int mask = 0x1;
  for (int i = 0; i < log2n; i++)
  {
    n <<= 1;
    n |= (x & 1);
    x >>= 1;
  }
  return n;
}
