#include "commonTest.h"
#include "sample2Mock.h"

extern "C"
{
#include "sample1.h"
}

using testing::SetArgPointee;

class Sample1Test : public testing::Test
{
public:
    Sample2Mock sample2Mock;
};

TEST_F(Sample1Test, first)
{
    EXPECT_CALL(sample2Mock, SampleFunc2_1(_)).WillRepeatedly(Return(1));
    SampleFunc1_1(2, 3);
}

TEST_F(Sample1Test, second)
{
    T_SAMPLE sample{2, 3};
    ON_CALL(sample2Mock, SampleFunc2_2(_))
        .WillByDefault(SetArgPointeeWithCast<0>(&sample));

    int ret = SampleFunc1_2();

    EXPECT_EQ(6, ret);
}
