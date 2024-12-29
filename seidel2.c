//a1x + b1y +c1z = d1    10 x +y +2z = 44      or x = (d1 - b1y - c1z) / a1          x = (44- y - 2z) /10
//a2x + b2y +c2z = d2    2x +10y + z = 51      or y = (d2 - a2x - c2z)/ b2           y = (51 - 2x- z) /10
//a3x + b3y +c3z = d3    x + 2y + 10z = 61      or z = (d3 - a3x - b3y)/ c3          z = (61 -x - 2y) /10

#include <stdio.h>
#include <math.h>

// Functions to calculate the new values for x, y, and z
float f1(float a1, float b1, float c1, float d1, float y, float z) {
    return (d1 - b1 * y - c1 * z) / a1;
}

float f2(float a2, float b2, float c2, float d2, float x, float z) {
    return (d2 - a2 * x - c2 * z) / b2;
}

float f3(float a3, float b3, float c3, float d3, float x, float y) {
    return (d3 - a3 * x - b3 * y) / c3;
}

int main() {
    // Variables to hold coefficients for each equation
    float a1, b1, c1, d1;  // Coefficients for the first equation: a1*x + b1*y + c1*z = d1
    float a2, b2, c2, d2;  // Coefficients for the second equation: a2*x + b2*y + c2*z = d2
    float a3, b3, c3, d3;  // Coefficients for the third equation: a3*x + b3*y + c3*z = d3

    float x0, y0, z0;  // Initial guesses
    float x1, y1, z1;  // Updated values after each iteration
    float allowederr, e1, e2, e3;  // Allowed error and error terms
    int iteration = 0;


    //we can take input in matrix form also
    // Input the coefficients for the three equations
    printf("Enter coefficients for the first equation (a1*x + b1*y + c1*z = d1): \n");
    scanf("%f %f %f %f", &a1, &b1, &c1, &d1);
    
    printf("Enter coefficients for the second equation (a2*x + b2*y + c2*z = d2): \n");
    scanf("%f %f %f %f", &a2, &b2, &c2, &d2);
    
    printf("Enter coefficients for the third equation (a3*x + b3*y + c3*z = d3): \n");
    scanf("%f %f %f %f", &a3, &b3, &c3, &d3);

    // Input initial guesses and allowed error
    printf("Enter the initial guesses for x0, y0, z0: \n");
    scanf("%f %f %f", &x0, &y0, &z0);
    
    printf("Enter allowed error: \n");
    scanf("%f", &allowederr);

    // Diagonal dominance check (for convergence)
    if (fabs(a1) >= fabs(b1) + fabs(c1) && fabs(b2) >= fabs(a2) + fabs(c2) && fabs(c3) >= fabs(a3) + fabs(b3)) {
        do {
            // Update x, y, and z using the functions
            x1 = f1(a1, b1, c1, d1, y0, z0);
            y1 = f2(a2, b2, c2, d2, x1, z0);
            z1 = f3(a3, b3, c3, d3, x1, y1);

            //if in matrix form then pass as mat[0][0], mat[0][1], mat [0][2], mat[0][3]

            // Calculate errors
            e1 = fabs(x1 - x0);
            e2 = fabs(y1 - y0);
            e3 = fabs(z1 - z0);

            // Update x0, y0, z0 for the next iteration
            x0 = x1;
            y0 = y1;
            z0 = z1;

            iteration++;

            printf("Iteration %d: x = %.4f, y = %.4f, z = %.4f\n", iteration, x0, y0, z0);
        } while (e1 > allowederr && e2 > allowederr && e3 > allowederr);

        printf("Solution after %d iterations:\n", iteration);
        printf("x = %.4f, y = %.4f, z = %.4f\n", x1, y1, z1);
    } else {
        printf("The system does not satisfy the diagonal dominance condition, so it may not converge.\n");
    }

    return 0;
}
