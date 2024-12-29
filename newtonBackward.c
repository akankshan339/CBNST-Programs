// Enter number of observations: 4
// Enter the values of x and corresponding y:
// 0 1
// 1 2
// 2 1
// 3 10
// Enter the value of x for which you want to find y: 0.5
//ans = 2.5
#include <stdio.h>
#include <math.h>

int findfact(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int n;
    printf("Enter number of observations: ");
    scanf("%d", &n);

    float x[n], y[n][n];
    float xvalue, yvalue = 0, h, u = 0, u1;

    // Input x and y values
    printf("Enter the values of x and corresponding y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
        scanf("%f", &y[i][0]);
    }

    // Input the x value for which to find y
    printf("Enter the value of x for which you want to find y: ");
    scanf("%f", &xvalue);

    h = x[1] - x[0];       // Calculate the step size
    u = (xvalue - x[n - 1]) / h;

    // Construct the backward difference table
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    // Print the backward difference table
    printf("Newton Backward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%0.1f\t", x[i]);
        for (int j = 0; j <= i; j++) {
            printf("%0.1f\t", y[i][j]);
        }
        printf("\n");
    }

    // Apply Newton's backward interpolation formula
    yvalue = y[n - 1][0];
    u1 = u;
    for (int i = 1; i < n; i++) {
        yvalue += (u1 * y[n - 1][i]) / findfact(i);
        u1 = u1 * (u + i);
    }

    printf("Value of y at x = %.2f is %.2f\n", xvalue, yvalue);
    return 0;
}


