#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#define SAMPLES 5000

std::vector<float> test(SAMPLES);

int main(int argc, char *argv[])
{
    for(int i = 0; i < SAMPLES; i++)
    {
        test.at(i) = sin(i/4) + sin(i/8);
    }

    plt::title("LMS Filter");
    plt::named_plot("PID controller", test);
    plt::show();
}