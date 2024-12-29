#include<stdio.h>
#include<math.h>

float f1(float y, float z) {
    return (44 - y - 2 * z) / 10;
}

float f2(float x, float z) {
    return (51 - 2 * x - z) / 10;
}

float f3(float x, float y) {
    return (61 - x - 2 * y) / 10;
}

int main() {
    float x0 = 0, y0 = 0, z0 = 0;           // Initial guesses
    float x1, y1, z1;                       //Updated values for each iteration
    float e1, e2, e3;                       // Error terms
    float allowederr;
    
    printf("Enter allowed Error:\n");
    scanf("%f", &allowederr);

    int iteration = 0;

// Check for diagonal dominance (for the system to converge)
    if (fabs(10) >= fabs(1) + fabs(2) && fabs(10) >= fabs(2) + fabs(1) && fabs(10) >= fabs(1) + fabs(2)) {
        do {
            // Compute new values using Gauss-Seidel formula
            x1 = f1(y0, z0);
            y1 = f2(x1, z0);  // Use latest value of x1
            z1 = f3(x1, y1);  // Use latest values of x1 and y1

            
            e1 = fabs(x1 - x0);            // Calculate errors
            e2 = fabs(y1 - y0);
            e3 = fabs(z1 - z0);

            
            x0 = x1;                // Update variables for the next iteration
            y0 = y1;
            z0 = z1;

            iteration++;

            printf("Iteration %d: x = %.4f, y = %.4f, z = %.4f \n", iteration, x0, y0, z0);
          
        } while (e1 > allowederr || e2 > allowederr || e3 > allowederr);

        printf("Solution after %d iterations:\n", iteration);
        printf("x = %.4f, y = %.4f, z = %.4f\n", x0, y0, z0);   //or x1, y1, z1
    } 
    else {
        printf("The system does not satisfy the diagonal dominance condition, so it may not converge.\n");
    }

    return 0;
}
