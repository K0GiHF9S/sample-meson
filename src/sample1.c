#include "sample1.h"
#include "sample2.h"

int SampleFunc1_1(int a, int b)
{
    int c = SampleFunc2_1(&a) * b;
    return SampleFunc2_1(&c);
}

int SampleFunc1_2()
{
    T_SAMPLE *pSample;
    SampleFunc2_2(&pSample);
    return pSample->a * pSample->b;
}
