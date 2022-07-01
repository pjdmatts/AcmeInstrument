#include <cmath>
#include "fourier.h"
#include "data.h"

std::shared_ptr<Data> Fourier::perform_fft(std::shared_ptr<Data> input_data)
{
    double n;
    auto data_ptr = std::shared_ptr<Data>{new Data()};
    std::cout << "What is the size N of the subset you want to analyze, to the nearest power of 2?" << std::endl;
    std::cin >> n;
    int log2n = std::log2(n);
    std::vector<double> x = input_data->getXData();
    std::vector<double> y = input_data->getYData();

    // the example we are using likes an array
    typedef std::complex<double> cx;
    cx a[y.size()];
    cx b[y.size()];
    std::copy(y.begin(), y.end(), a);
    Calcfft fft_calc = Calcfft();
    fft_calc.fft(a, b, log2n);

    // now we need to interpet the data in b
    double fs;
    std::cout << "What rate, in Hz, was your data sampled at?" << std::endl;
    std::cin >> fs;
    float df = fs / n;
    std::cout << "Setting frequency bin size to " << df << "Hz" << std::endl;

    std::vector<double> bin_data;

    for (int i = 0; i < n / 2; i++)
    {
        bin_data.push_back(i * df);
    }

    std::vector<double> abs_data;

    for (int i = 0; i < n / 2; i++)
    {
        double abs = std::abs(b[i]);
        abs_data.push_back(abs);
    }

    data_ptr->setXData(bin_data);
    data_ptr->setYData(abs_data);
    return data_ptr;
}
