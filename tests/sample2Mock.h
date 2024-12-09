#include "commonTest.h"

extern "C"
{
#include "sample2.h"
}

class Sample2Mock : public GMockHelper<Sample2Mock>
{
public:
    MOCK_METHOD(int, SampleFunc2_1, (int *));
    MOCK_METHOD(void, SampleFunc2_2, (void *));
};
