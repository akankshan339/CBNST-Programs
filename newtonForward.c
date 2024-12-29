#include <stdio.h>

// Function to calculate factorial
int findFact(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    printf("Enter the number of observations: ");
    scanf("%d", &n);

    // Input arrays for x and y values
    float x[n], y[n][n];
    printf("Enter the values of x and y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i][0]);
    }

    // Input the value of x for which y is to be interpolated
    float xvalue, yvalue, h, u, u1;
    printf("Enter the value of x to find y or f(x): ");
    scanf("%f", &xvalue);

    // Calculate step size (h) and u
    h = x[1] - x[0];
    u = (xvalue - x[0]) / h;

    // Construct the forward difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // Print the forward difference table
    printf("Gauss Forward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("%.4f\t", y[i][j]);
        }
        printf("\n");
    }

    // Apply the Gauss Forward Interpolation formula
    yvalue = y[0][0]; // First term
    u1 = u;           // Initialize u1
    for (int i = 1; i < n; i++) {
        yvalue += (u1 * y[0][i]) / findFact(i);
        u1 *= (u - i); // Update u1 for the next term
    }

    // Output the result
    printf("Value of y at x = %.2f is %.4f\n", xvalue, yvalue);
    return 0;
}
