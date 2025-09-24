#include <stdio.h>
#include <stdlib.h>
#include "h/perceptron.h"

void perceptron_demo() {
    double X[][2] = {
        { 2.5,  1.8},
        { 1.7,  2.2},
        { 2.2,  3.0},
        {-1.8, -2.0},
        {-2.2, -1.3},
        {-2.5, -2.5}
    };
    int Ys[] = {+1, +1, +1, -1, -1, -1};
    int N = sizeof(X) / sizeof(X[0]);
    int D = 2;

    double w[2] = {0.1, -0.1};
    double b = 0.0;
    double lr = 0.1;
    int epochs = 50;

    for (int epoch = 0; epoch < epochs; ++epoch) {
        int errors = 0;
        for (int i = 0; i < N; ++i) {
            double dot = w[0]*X[i][0] + w[1]*X[i][1] + b;
            int pred = (dot >= 0.0) ? +1 : -1;
            if (pred != Ys[i]) {
                w[0] += lr * Ys[i] * X[i][0];
                w[1] += lr * Ys[i] * X[i][1];
                b += lr * Ys[i];
                errors++;
            }
        }
        printf("[Perceptron] epoch %d  errors=%d  w=(%.4f, %.4f)  b=%.4f\n",
               epoch, errors, w[0], w[1], b);
        if (errors == 0) break;
    }

    printf("[Perceptron] final model: w=(%.4f, %.4f)  b=%.4f\n", w[0], w[1], b);
    for (int i = 0; i < N; ++i) {
        double dot = w[0]*X[i][0] + w[1]*X[i][1] + b;
        int pred = (dot >= 0.0) ? +1 : -1;
        printf("[Perceptron] (%.2f, %.2f)  y=%d  pred=%d  margin=%.4f\n",
               X[i][0], X[i][1], Ys[i], pred, dot);
    }
}

