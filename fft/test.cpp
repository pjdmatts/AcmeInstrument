#include <iostream>
#include <complex>
#include <typeinfo>
using namespace std;

int main() {
    double x = 12;
    cout << "Type of x : " << typeid(x).name() << endl;
    typedef complex<double> cx;
    cx a[8];
    cout << "Type of a : " << typeid(a).name() << endl;
}