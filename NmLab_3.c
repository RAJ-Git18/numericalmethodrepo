#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    float x[50], y[50], sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0,a,b;

    printf("\nFitting the curve using the least square method:\n");
    printf("Enter the number of the data points: ");
    scanf("%d", &n);
    printf("Enter the value of the corresponding x and y: ");

    // for inserting the value of x and y
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
        scanf("%f", &y[i]);
    }
    printf("\nHere is the entered data points: \n");
    printf("\n---------------------------------------------------------------------------------------------------------------\n");
    printf("x |");
    for (i = 0; i < n; i++)
    {
        printf(" %f |", x[i]);
    }
    printf("\n---------------------------------------------------------------------------------------------------------------\n");
    printf("y |");

    for (i = 0; i < n; i++)
    {
        printf(" %f |", y[i]);
    }
    printf("\n---------------------------------------------------------------------------------------------------------------\n");

    // Calculation of required float variable
    for (i = 0; i < n; i++)
    {
        sumx = sumx + x[i];
        sumy = sumy + y[i];
        sumx2 = sumx2 + x[i] * x[i];
        sumxy = sumxy + x[i] * y[i];
    }
       

    b = (n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    a = (sumy-b*sumx)/n;
    printf("\nThe required value of a and b are: %f and %f\n",a ,b);
    printf("\nThe fitted regression line is: y = %f + %fx\n ",a,b);

    return 0;
}