#include "data_stat.h"

double max(double *data, int n) {
    double tpm = -100000000;
    for (int i = 0; i < n; i++) {
        if (data[i] > tpm) {
            tpm = data[i];
        }
    }
    return tpm;
}

double min(double *data, int n) {
    double tpm = 100000000;
    for (int i = 0; i < n; i++) {
        if (data[i] < tpm) {
            tpm = data[i];
        }
    }
    return tpm;
}

double mean(double *data, int n) {
    double sum = 0;

    for (double *i = data; i - data < n; ++i) {
        sum = sum + (*i);
    }
    sum = sum / (double)n;
    return sum;
}
double variance(double *data, int n) {
    double sum = 0;
    for (double *i = data; i - data < n; ++i) {
        sum += pow(*i, 2);
    }
    double x = mean(data, n);
    sum = sum / (double)n - pow(x, 2);
    return sum;
}
