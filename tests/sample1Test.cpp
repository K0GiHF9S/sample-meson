#include "commonTest.h"
#include "sample2Mock.h"

extern "C"
{
#include "sample1.h"
}

class Sample1Test : public testing::Test
{
public:
    Sample2Mock sample2Mock;
};

TEST_F(Sample1Test, first)
{
    EXPECT_CALL(sample2Mock, SampleFunc2(_)).WillRepeatedly(Return(1));
    SampleFunc1(2, 3);
}
