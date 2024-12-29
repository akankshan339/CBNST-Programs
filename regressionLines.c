#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n], sumX = 0, sumY = 0, sumX2 = 0, sumY2 = 0, sumXY = 0;

    printf("Enter the data points of x: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter the data points of y: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    // Calculate summations
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    // Calculate coefficients for regression of y on x
    float b_y_on_x = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    float a_y_on_x = (sumY - b_y_on_x * sumX) / n;

    // Calculate coefficients for regression of x on y
    float b_x_on_y = (n * sumXY - sumX * sumY) / (n * sumY2 - sumY * sumY);
    float a_x_on_y = (sumX - b_x_on_y * sumY) / n;

    // Display regression lines
    printf("Regression line of y on x: y = %.2f + %.2fx\n", a_y_on_x, b_y_on_x);
    printf("Regression line of x on y: x = %.2f + %.2fy\n", a_x_on_y, b_x_on_y);

    return 0;
}



// #include <stdio.h>

// // Function to calculate mean
// double mean(double arr[], int size) {
//     double sum = 0.0;
//     for (int i = 0; i < size; i++) {
//         sum += arr[i];
//     }
//     return sum / size;
// }

// int main() {
//     // Sample data points
//     int n;
//     scanf("%d",&n);
//     float x[n];
//     float y[n];// Dependent variable
//     for (int i=0;i<n;i++){
//         scanf("%f%f", &x[i],&y[i]);
//     }

    

//     // Calculate means
//     double x_mean = mean(x, n);
//     double y_mean = mean(y, n);

//     // Variables for regression calculations
//     double numerator_xy = 0.0, denominator_x = 0.0;
//     double numerator_yx = 0.0, denominator_y = 0.0;

//     for (int i = 0; i < n; i++) {
//         numerator_xy += (x[i] - x_mean) * (y[i] - y_mean);
//         denominator_x += (x[i] - x_mean) * (x[i] - x_mean);

//         numerator_yx += (x[i] - x_mean) * (y[i] - y_mean);
//         denominator_y += (y[i] - y_mean) * (y[i] - y_mean);
//     }

//     // Regression y on x
//     double m_y_on_x = numerator_xy / denominator_x;
//     double c_y_on_x = y_mean - m_y_on_x * x_mean;

//     // Regression x on y
//     double m_x_on_y = numerator_yx / denominator_y;
//     double c_x_on_y = x_mean - m_x_on_y * y_mean;

//     // Print results
//     printf("Regression (y on x): y = %.2fx + %.2f\n", m_y_on_x, c_y_on_x);
//     printf("Regression (x on y): x = %.2fy + %.2f\n", m_x_on_y, c_x_on_y);

//     return 0;
// }






