#include <stdio.h>
#include <math.h>

#define EPS1 0.000001
#define EPS2 0.01
#define MAX_ITER 1000


double f(double x) {
    return pow(x, 3) - 3 * pow(x, 2) - 24 * x - 5;
}

double bisection(double a, double b, double eps) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval for bisection method.\n");
        return NAN;
    }

    double c;
    int iter = 0;

    while ((b - a) >= eps && iter < MAX_ITER) {
        c = (a + b) / 2;

        if (f(c) == 0.0) {
            break;
        }
        else if (f(a) * f(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }

        iter++;
    }

    return c;
}

int main() {
    double a = -5, b = 5; 

    printf("Bisection Method:\n");
    printf("Root with EPS1 = %lf\n", bisection(a, b, EPS1));
    printf("Root with EPS2 = %lf\n", bisection(a, b, EPS2));

    return 0;
}
