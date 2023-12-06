#include <cstdint>
#include <vector>

class LMS
{
  public:
    LMS(uint8_t inputs, float learning_rate);
    float evaluate(std::vector<float> inputs);
    void error(float error, std::vector<float> inputs);

  protected:
  private:
    std::vector<float> _weights;
    float              _learning_rate;
};