//root 12 to 5 decimal places x = root 12 , so x^2 = 12  so f(x) = x^2 - 12 =0 and f'(x) = 2x
#include <stdio.h>
#include <math.h>

// Define the function f(x) = 3*x = cos x +1 correct upto 4 decimal places  f'(x) =  3 + sin (x)
float f(float x) {
    //return 3*x - cos(x) - 1;
    return x*x- 12;
}

//  derivative of f(x)
float df(float x) {
    //return 3 + sin (x);
    return 2*x;
}

int main() {
    int iter = 0;
    float x0, x1, allowederr;

    // Input initial guess
    printf("Enter the initial guess:\n");
    scanf("%f", &x0);

    // Input allowed error
    printf("Enter allowed error:\n");
    scanf("%f", &allowederr);

    // Newton raphson Method iterations
    do {
        iter++;
        x1 = x0 - f(x0) / df(x0);

        printf("%d iteration, x0 = %f, x1 = %f, \n", iter, x0, x1);

        // Check for convergence
        if (fabs(x0 - x1) <= allowederr) {
            printf("Root of the equation is %f after %d iterations.\n", x1, iter);
            break;
        }

        // Update x0 and x1 for the next iteration
        x0 = x1;

        // Limit iterations to avoid infinite loops
        // if (iter > 100) {
        //     printf("Exceeded maximum iterations.\n");
        //     break;
        // }

    } while (1);

    return 0;
}
