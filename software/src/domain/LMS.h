#include <vector>
#include <cstdint>

class LMS
{
  public:
    LMS(uint8_t inputs);
  protected:
  private:
    std::vector<float> weights;
};