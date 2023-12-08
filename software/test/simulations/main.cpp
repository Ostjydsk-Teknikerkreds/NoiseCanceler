#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <deque>

#include "lms.h"

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#define SAMPLES 10000000
#define TAPS 128
#define DELAY 20
#define LEARNING_RATE 0.005f
#define POWER_LIMIT 5

#define GRAPH_SAMPLE_RATE 100

std::vector<float> input(SAMPLES / GRAPH_SAMPLE_RATE);
std::vector<float> output(SAMPLES / GRAPH_SAMPLE_RATE);
std::vector<float> counter(SAMPLES / GRAPH_SAMPLE_RATE);

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
        float noise = (float) (rand() % 100) / 1000 - 0.05f;
        float new_input;
        //if(i < SAMPLES / 2)
        //{
            new_input = cos((float)i / 8) + cos((float)i / 10) + sin((float)i/12) + noise;
        //}
        //else
        //{
          //  new_input = cos((float)i / 9) + cos((float)i / 11 + 5) + sin((float)i/6) + noise;
        //}

        inputs.push_back(new_input);
        inputs.pop_front();

        float counter_sound = lms.evaluate({inputs.begin(), inputs.end()});

        if(counter_sound > POWER_LIMIT)
            counter_sound = POWER_LIMIT;
        if(counter_sound < -POWER_LIMIT)
            counter_sound = -POWER_LIMIT;

        delay.push(counter_sound);
        delay.pop();

        float feedback = new_input + delay.front();

        lms.error(feedback, {inputs.begin(), inputs.end()});

        if(i % GRAPH_SAMPLE_RATE == 0)
        {
            counter.at(i / GRAPH_SAMPLE_RATE) = delay.front();
            input[i / GRAPH_SAMPLE_RATE] = new_input;
            output.at(i / GRAPH_SAMPLE_RATE) = feedback; 
        }
    }

    plt::title("LMS Filter");
    plt::named_plot("Input", input);
    plt::named_plot("Counter", counter);
    plt::named_plot("Output", output);
    plt::show();
}