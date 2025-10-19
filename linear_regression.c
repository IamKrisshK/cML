#include <stdio.h>
#include <math.h>
#include "h/linear_regression.h"

void linear_regression(double x[], double y[], int n, double *w, double *b, double lr, int epochs) {
    if (lr <= 0.0)     lr = 0.01;
    if (epochs <= 0)   epochs = 5000; 

    *w = 0.0;
    *b = 0.0;

    for (int epoch = 0; epoch < epochs; ++epoch) {
        double dw = 0.0, db = 0.0, loss = 0.0;

        for (int i = 0; i < n; ++i) {
            double pred = (*w) * x[i] + (*b);
            double err = y[i] - pred;
            loss += err * err;
            dw += -2.0 * x[i] * err;
            db += -2.0 * err;
        }

        loss /= n;
        dw /= n;
        db /= n;
        *w -= lr * dw;
        *b -= lr * db;

        if (epoch % 250 == 0) {
            printf("[LR] epoch %d  loss=%.6f  w=%.6f  b=%.6f\n", epoch, loss, *w, *b);
        }
    }
    double loss = 0.0;
    for (int i = 0; i < n; ++i) {
        double pred = (*w) * x[i] + (*b);
        double err = y[i] - pred;
        loss += err * err;
        printf("[LR] x=%.2f  y=%.2f  pred=%.4f\n", x[i], y[i], pred);
    }

    loss /= n;
    printf("[LR] final MSE=%.6f  final w=%.6f  final b=%.6f\n", loss, *w, *b);
}
