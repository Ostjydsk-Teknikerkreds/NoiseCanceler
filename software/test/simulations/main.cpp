#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <deque>

extern "C"
{
#include "lms.h"
}

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#define SAMPLES 1000000
#define TAPS 128
#define DELAY 20
#define LEARNING_RATE 0.005f
#define POWER_LIMIT 5

#define GRAPH_SAMPLE_RATE 10

std::vector<float> input(SAMPLES / GRAPH_SAMPLE_RATE);
std::vector<float> counter(SAMPLES / GRAPH_SAMPLE_RATE);
std::vector<float> output(SAMPLES / GRAPH_SAMPLE_RATE);

std::deque<float> inputs;
std::queue<float> delay;

lms_filter_t filter;

int deque_to_array(std::deque<float> *deque, float *buffer, int size)
{
    int i;
    for(i = 0; i < deque->size() && i < size; i++)
    {
        buffer[i] = deque->at(i);
    }
    return i;
}

int main(int argc, char *argv[])
{
    lms_filter_init(&filter, TAPS, LEARNING_RATE, 1E-8f);

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
        new_input = cos((float)i / 8) + cos((float)i / 10) + sin((float)i/12) + noise;

        inputs.push_back(new_input);
        inputs.pop_front();

        float input_arr[TAPS];
        int input_size = deque_to_array(&inputs, input_arr, TAPS);
        float counter_sound = lms_filter_evaluate(&filter, input_arr, input_size);

        if(counter_sound > POWER_LIMIT)
            counter_sound = POWER_LIMIT;
        if(counter_sound < -POWER_LIMIT)
            counter_sound = -POWER_LIMIT;

        delay.push(counter_sound);
        delay.pop();

        float feedback = new_input + delay.front();
        lms_filter_error(&filter, input_arr, input_size, feedback);

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