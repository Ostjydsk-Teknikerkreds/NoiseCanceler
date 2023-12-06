#include <vector>
#include <cstdint>

class LMS
{
  public:
    LMS(uint8_t inputs);
    float evaluate(std::vector<float> inputs);
  protected:
  private:
    std::vector<float> _weights;
};