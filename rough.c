#include<stdio.h>
int main(){
    int n;
    printf("Enter the total number of observations: ");
    scanf("%d",&n);
    float x[n],y[n];
    printf("Enter x & y for %d observations: ",n);
    float sum_x=0, sum_y=0, sum_xy=0, sum_x2=0;
    for (int i=0; i<n; i++){
        scanf("%f%f",&x[i],&y[i]);
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy += x[i]*y[i];
        sum_x2 += x[i]*x[i];
    }
    float b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    float a = (sum_y - b * sum_x) / n;
    printf("The equation of the best-fit line is: y = %.2f + %.2fx\n", a, b);
    return 0;    
}