#include <stdio.h>
#include <string.h>
#include "h/linear_regression.h"
#include "h/perceptron.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [lr|p]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "lr") == 0) {
        linear_regression_demo();
    } else if (strcmp(argv[1], "p") == 0) {
        perceptron_demo();
    } else {
        printf("Unknown option '%s'\n", argv[1]);
        return 1;
    }
    return 0;
}

