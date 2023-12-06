#include "LMS.h"

#include <cassert>

LMS::LMS(uint8_t inputs) : _weights(inputs)
{
    for(uint8_t i = 0; i < inputs; i++)
    {
        _weights.at(i) = 1.f;
    }
}

float LMS::evaluate(std::vector<float> inputs)
{
    assert(_weights.size() == inputs.size());
    float ret = 0;
    for(uint8_t i = 0; i < inputs.size(); i++)
    {
        ret += inputs.at(i) * _weights.at(i);
    }
    return ret;
}