#include <stdio.h>

#include "sample1.h"
#include "sample2.h"

#define PROJECT_NAME "sample-meson"

int main(int argc, char **argv) {
    if(argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    printf("This is project %s.\n", PROJECT_NAME);
    SampleFunc1_1(3, 2);
    printf("This is project %d.\n", SampleFunc2_1(NULL));
    return 0;
}
