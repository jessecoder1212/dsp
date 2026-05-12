#include <stdio.h>
#include <math.h>

#define PI 3.14159264

float x[256], y[256];

int main()
{
    float fs = 10000.0;
    float T = 1.0 / fs;
    float t = 0.0;

    int i;

    // Generate input signal
    for(i = 0; i < 256; i++)
    {
        x[i] = sin(2 * PI * 117.18 * t)
             + sin(2 * PI * 585.93 * t)
             + sin(2 * PI * 3906.25 * t);

        t += T;
    }

    // Initial output
    y[0] = 0;

    // Butterworth LPF
    for(i = 1; i < 256; i++)
    {
        y[i] = -0.1583844 * y[i - 1]
             + 0.5791922 * (x[i] + x[i - 1]);
    }

    return 0;
}
