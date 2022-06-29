// $ g++ -std=c++11 your_file.cpp -o your_program
#include <iostream> /* printf */
#include <math.h>   /* sin */
#include <vector>
#include <fstream>
#include <complex>
#include <cmath>
#include <iterator>

using namespace std;

#define PI 3.14159265

void fill_vec(vector<double> &vec, float a, float inc, float b)
{
    for (float n = a; n <= b; n += inc)
        vec.push_back(n);
}

void cos_vec(vector<double> &vec1, vector<double> &vec2, float A, float fc, float phi)
{
    for (float t : vec1)
    {
        float y = A * cos(2 * PI * fc * t + phi);
        vec2.push_back(y);
    }
}

void make_file(vector<double> &x, vector<double> &y, string filename)
{
    ofstream myFile(filename);
    for (int i = 0; i < x.size(); ++i)
    {
        myFile << x.at(i) << "," << y.at(i) << "\n";
    }
    myFile.close();
}

unsigned int bitReverse(unsigned int x, int log2n)
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

//template <class Iter_T>
void fft(vector<complex<double> > a, vector<complex<double> > b, int log2n)
{
    //typedef typename iterator_traits<Iter_T>::value_type complex;
    const complex<double>  J(0, 1);
    int n = 1 << log2n;
    for (unsigned int i = 0; i < n; ++i)
    {
        b[bitReverse(i, log2n)] = a[i];
    }
    for (int s = 1; s <= log2n; ++s)
    {
        int m = 1 << s;
        int m2 = m >> 1;
        complex<double>  w(1, 0);
        complex<double>  wm = exp(-J * (PI / m2));
        for (int j = 0; j < m2; ++j)
        {
            for (int k = j; k < n; k += m)
            {
                complex<double>  t = w * b[k + m2];
                complex<double>  u = b[k];
                b[k] = u + t;
                b[k + m2] = u - t;
            }
            w *= wm;
        }
    }
}

int main()
{
    float A = 0.5;                // amplitude of the cosine wave
    float fc = 10;                // frequency of the cosine wave
    float phase = 0;             // desired phase shift of the cosine in degrees
    float fs = 32 * fc;           // sampling frequency with oversampling factor 32
    float phi = phase * PI / 180; // convert phase shift in degrees in radians
    vector<double> x_vec;
    vector<double> y_vec;
    fill_vec(x_vec, 0.0, 1 / fs, 2 - 1 / fs);
    cos_vec(x_vec, y_vec, A, fc, phi);
    make_file(x_vec, y_vec, "foo4.csv");
    // let's understand the size of y_vec
    cout << "size of x_vec is: " << y_vec.size() << endl;
    // for (int i = 0; i < x_vec.size(); i++)
    // {
    //     cout << x_vec.at(i) << endl;
    // }

    cout << "size of y_vec is: " << y_vec.size() << endl;
    // convert the y_vec into a complex array
    vector<complex<double> > y_cx;
    vector<complex<double> > b;

    int N = 512;

    for (int i = 0; i < N; i++)
    {
        complex<double> temp(y_vec[i], 0);
        y_cx.push_back(temp);
    }
    cout << "size of y_cx is: " << y_cx.size() << endl;

    // fft we got from c++ cookbook needs an array

    // typedef complex<double> cx;
    // cx a[y_cx.size()];
    // copy(y_cx.begin(), y_cx.end(), a);
    // cx b[y_cx.size()];

    // Doing fft things
    fft(y_cx, b, 9);

    // for (int i = 0; i < N; i++)
    //     cout << abs(b[i]) << "\n";

    double df=fs/N; //frequency resolution
    vector<double> f_vec;
    vector<double> abs_vec;

    for (int i = 0; i < N/2; i++){
        f_vec.push_back(i*df);
    }

    for(int i = 0; i < N/2; i++){
        abs_vec.push_back(abs(b[i]));
    }

    make_file(f_vec, abs_vec, "abs.csv");

    cout << "fs is: " << df << endl;
    cout << "size of f_vec is: " << f_vec.size() << endl;
    cout << "size of abs_vec is: " << abs_vec.size() << endl;

}
