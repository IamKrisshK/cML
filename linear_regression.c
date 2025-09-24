#include <stdio.h>
#include <math.h>
#include "h/linear_regression.h"

void linear_regression_demo() {
    double xs[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
    double ys[] = {1.1, 3.6, 6.0, 7.9, 11.2, 13.1};
    int N = sizeof(xs) / sizeof(xs[0]);

    double w = 0.0;
    double b = 0.0;
    double lr = 0.01;
    int epochs = 5000;

    for (int epoch = 0; epoch < epochs; ++epoch) {
        double dw = 0.0, db = 0.0, loss = 0.0;
        for (int i = 0; i < N; ++i) {
            double pred = w * xs[i] + b;
            double err = ys[i] - pred;
            loss += err * err;
            dw += -2.0 * xs[i] * err;
            db += -2.0 * err;
        }
        loss /= N; dw /= N; db /= N;

        w -= lr * dw;
        b -= lr * db;

        if (epoch % 1000 == 0) {
            printf("[LR] epoch %d  loss=%.6f  w=%.6f  b=%.6f\n", epoch, loss, w, b);
        }
    }

    double loss = 0.0;
    for (int i = 0; i < N; ++i) {
        double pred = w * xs[i] + b;
        double err = ys[i] - pred;
        loss += err * err;
        printf("[LR] x=%.2f  y=%.2f  pred=%.4f\n", xs[i], ys[i], pred);
    }
    loss /= N;
    printf("[LR] final MSE=%.6f  final w=%.6f  final b=%.6f\n", loss, w, b);
}

