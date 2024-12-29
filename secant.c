#include <stdio.h>
#include <math.h>

float f(float x) {
   // return (x * x * x - 5 * x + 1);  // f(x) = x^3 - 5x + 1
   return (x * x) * (exp(-x / 2)) - 1;
}

float g(float x0, float x1) {
    // Corrected secant method formula with proper parentheses
    float x2 = x1 - ((x1 - x0) * f(x1)) / (f(x1) - f(x0));
    return x2;
}

int main() {
    int flag = 0, iter = 0;
    float x0, x1, allowederr;

    do {
        printf("Enter the initial guess of x0 and x1:\n");
        scanf("%f%f", &x0, &x1);

        if (f(x0) * f(x1) < 0) {  // Check if a root exists between x0 and x1
            flag = 1;
            printf("Initial guess accepted.\n");
        } else {
           // printf("Case not satisfied, try again...\n");
           printf("Wrong initial guess, f(x0)* f(x1) = %f is not less than 0. Try again.\n", fabs(f(x0)) * fabs(f(x1)));
        }
    } while (flag != 1);

    printf("Enter allowed error:\n");
    scanf("%f", &allowederr);

    do {
        iter++;
        // Compute the next approximation
        float x2 = g(x0, x1);
        printf("%d iteration, value of x0 is %f, value of  x1 is %f and g(x0, x1) is %f\n", iter, x0, x1, x2);
        // Check for convergence
        if (fabs(x1 - x2) <= allowederr) {
            flag = 0;
            printf("Root of the equation is %f after %d iterations.\n", x2, iter);
            break;
        } 
        else {
            x0 = x1;  // Update x0 for the next iteration
            x1 = x2;  // Update x1 for the next iteration
           
        }

    } while (flag != 0);  // Infinite loop until convergence

    return 0;
}
