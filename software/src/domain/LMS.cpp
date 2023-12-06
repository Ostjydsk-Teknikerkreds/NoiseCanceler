#include "LMS.h"

#include <cassert>

LMS::LMS(uint8_t inputs, float learning_rate) : _weights(inputs), _learning_rate(learning_rate)
{
    for (uint8_t i = 0; i < inputs; i++)
    {
        _weights.at(i) = 0.01f;
    }
}

float LMS::evaluate(std::vector<float> inputs)
{
    assert(_weights.size() == inputs.size());
    float ret = 0;
    for (uint8_t i = 0; i < inputs.size(); i++)
    {
        ret += inputs.at(i) * _weights.at(i);
    }
    return ret;
}

void LMS::error(float error, std::vector<float> inputs)
{
    assert(_weights.size() == inputs.size());
    for(uint8_t i = 0; i < _weights.size(); i++)
    {
        _weights.at(i) -= error * _learning_rate * inputs[i] * _weights.at(i);
    }
}