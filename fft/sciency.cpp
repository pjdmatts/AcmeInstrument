// $ g++ -std=c++11 your_file.cpp -o your_program
#include <iostream>    /* printf */
#include <math.h>       /* sin */
#include <vector>
#include <fstream>

#define PI 3.14159265

void fill_vec(std::vector<float>& vec, float a, float inc, float b)
{
    for(float n = a; n <= b; n += inc)
      vec.push_back(n);
}

void cos_vec(std::vector<float>& vec1, std::vector<float>& vec2, float A, float fc, float phi) 
{
  for(float t : vec1) {
    float y = A*cos(2*PI*fc*t+phi);
    vec2.push_back(y);
}
}

void make_file(std::vector<float>& x, std::vector<float>& y)
{
std::ofstream myFile("foo.csv");
  for(int i = 0; i < x.size(); ++i)
    {
        myFile << x.at(i) << "," << y.at(i) <<"\n";

    }
    myFile.close();
}

int main(){
  float A = 0.5; //amplitude of the cosine wave
  float fc=10;//frequency of the cosine wave
  float phase=30; //desired phase shift of the cosine in degrees
  float fs=32*fc; //sampling frequency with oversampling factor 32
  float phi = phase*PI/180; //convert phase shift in degrees in radians
  std::vector<float> x_vec;
  std::vector<float> y_vec;
  fill_vec(x_vec, 0.0, 1/fs, 2-1/fs);  
  cos_vec(x_vec, y_vec, A, fc, phi);
  make_file(x_vec, y_vec);
}





