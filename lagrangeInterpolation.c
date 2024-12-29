#include <stdio.h>

int main() {
    int n;
    float xvalue, result = 0.0;

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    // Input the values of x and y
    printf("Enter the values of x and y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
        scanf("%f", &y[i]);
    }

    // Input the value of x for which f(x) is to be calculated
    printf("Enter the value of x to find f(x): ");
    scanf("%f", &xvalue);

    // Perform Lagrange interpolation
    for (int i = 0; i < n; i++) {
        float term = y[i]; // Initialize term with y[i]

        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (xvalue - x[j]) / (x[i] - x[j]);
            }
        }

        result += term; // Add the term to the result
    }

    // Output the result
    printf("\nThe interpolated value at x = %.2f is %.4f\n", xvalue, result);

    return 0;
}
