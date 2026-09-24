#include <stdio.h>
#include <math.h>

double func(double x) {
    return pow(x / 100 - 5, 5)
           - pow(x / 50 + 10, 4)
           - pow(x / 25 - 15, 3)
           - (x * x)
           - 10;
}

int main() {
    double X1, X2, delta;
    unsigned int N;
    int mode;

    printf("Enter mode [1, 2]: ");
    scanf("%d", &mode);


    if (mode != 1 && mode != 2) {
        printf("invalid mode \n");
        return 0;
    }

    printf("Enter X1: ");
    scanf("%lf", &X1);

    printf("Enter X2: ");
    scanf("%lf", &X2);

    if (X1 > X2) { printf("X2 cant be > than X1\n"); return 0; }

    if (mode == 1) {
        printf("Enter N: ");
        scanf("%u", &N);

        if (N <= 1) { printf("N cant be <= 1\n"); return 0; }

        delta = (X2 - X1) / (N - 1);
    } else if (mode == 2) {
        printf("Enter delta: ");
        scanf("%lf", &delta);

        if (delta < 0) { printf("delta cant be < 0\n"); return 0; }

        N = (unsigned int)((X2 - X1) / delta) + 1;
    }

    printf("X1 = %lf, X2 = %lf, N = %d  delta = %lf\n", X1, X2, N, delta);

    return 0;
}