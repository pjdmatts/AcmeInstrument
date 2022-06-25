// $ g++ -std=c++11 your_file.cpp -o your_program
#include <iostream>    /* printf */
#include <math.h>       /* sin */
#include <vector>
using std::vector;
using std::cout;

#define PI 3.14159265

void fill_vec(vector<float>& vec, float a, float inc, float b)
{
    for(float n = a; n <= b; n += inc)
      vec.push_back(n);
}

void cos_vec(vector<float>& vec1, vector<float>& vec2, float A, float fc, float phi) 
{
  for(float t : vec1) {
    float x = A*cos(2*PI*fc*t+phi);
    vec2.push_back(x);
}
}

int main(){
  float A = 0.5; //amplitude of the cosine wave
  float fc=10;//frequency of the cosine wave
  float phase=30; //desired phase shift of the cosine in degrees
  float fs=32*fc; //sampling frequency with oversampling factor 32
  float phi = phase*PI/180; //convert phase shift in degrees in radians
  vector<float> t_vec;
  vector<float> x_vec;
  fill_vec(t_vec, 0.0, 1/fs, 2-1/fs);  
  cos_vec(t_vec, x_vec, A, fc, phi);
}





