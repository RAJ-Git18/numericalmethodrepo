// HEADER FILE
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) ( x*sin(x) -1 )

int main()
{
    float x0, x1, x2, f2, f0, f1, e;
    int iteration = 1;

INPUT:
    printf("\nEnter the value of initial guesses (x0 and x1) and predefined error(e): \t");
    scanf("%f %f %f", &x0, &x1, &e);

    f0 = f(x0);
    f1 = f(x1);

    if (f0 * f1 > 0)
    {
        printf("\nIncorrect initial guess.\n");
        goto INPUT;
    }

    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("\nIteration \t\t x0 \t\t\t x1 \t\t\t x2 \t\t\t f(x2) \n");
    printf("\n------------------------------------------------------------------------------------------------------------\n");

    do
    {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        printf("%d \t\t\t %f \t\t %f \t\t %f \t\t %f \n", iteration, x0, x1, x2, f2);

        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else 
        {
            x0 = x2;
            f0 = f2;
        }
        iteration ++;
    } while (fabs(f2)>e);

    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("\nThe approximate root is: %f", x2);

    return 0;
    
}
