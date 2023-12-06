#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <deque>

#include "LMS.h"

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#define SAMPLES 400000
#define TAPS 32
#define DELAY 20
#define LEARNING_RATE 0.004f

std::vector<float> input(SAMPLES);
std::vector<float> output(SAMPLES);
std::vector<float> counter(SAMPLES);

std::deque<float> inputs;
std::queue<float> delay;

LMS lms(TAPS, LEARNING_RATE);

int main(int argc, char *argv[])
{
    for(int i = 0; i < DELAY; i++)
    {
        delay.push(0);
    }

    for(int i = 0; i < TAPS; i++)
    {
        inputs.push_back(0);
    }

    for(int i = 0; i < SAMPLES; i++)
    {
        input.at(i) = sin((float)i / 4);

        inputs.push_back(input.at(i));
        inputs.pop_front();

        float counter_sound = lms.evaluate({inputs.begin(), inputs.end()});
        delay.push(counter_sound);
        delay.pop();
        counter.at(i) = delay.front();

        float feedback = input.at(i) + delay.front();
        lms.error(feedback, {inputs.begin(), inputs.end()});
        output.at(i) = feedback;
    }

    plt::title("LMS Filter");
    plt::named_plot("Input", input);
    plt::named_plot("Counter", counter);
    plt::named_plot("Output", output);
    plt::show();
}