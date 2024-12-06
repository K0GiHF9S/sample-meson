#include "sample1.h"
#include "sample2.h"

int SampleFunc1(int a, int b)
{
    int c = SampleFunc2(&a) * b;
    return SampleFunc2(&c);
}
