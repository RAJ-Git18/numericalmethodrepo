// HEADER FILE
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define exp 2.71828

//#define f(x) (pow(x, 3) - 2 * x - 5)
//#define f(x) (3 * x + sin(x) - pow(exp, x))
//#define f(x) (x*pow(exp,x)-cos(x))
#define f(x) (tan(x) + tanh(x))
//#define f(x) (pow(exp, cos(x)) - sin(x))

int main()
{
    float x0, e, f0, x1, df0, f1, x2, f2;
    int iteration = 1, N;

    printf("\nEnter the value of initial guess (x0 and x1), predefined error(e), maximum no of iteration(N): \t");
    scanf("%f %f %f %d", &x0, &x1, &e, &N);

    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("Iteration \t\t x0 \t\t\t x1 \t\t\t x2 \t\t\t f(x2) ");
    printf("\n------------------------------------------------------------------------------------------------------------\n");

    do
    {
        f0 = f(x0);
        f1 = f(x1);

        if (df0 == 0)
        {
            printf("Mathematical error.\n");
            break; // Exit the loop in case of mathematical error
        }
        else
        {

            x2 = x1 - ((x1 - x0) / (f1 - f0)) * f1;

            printf("%d \t\t\t %f \t\t %f \t\t %f \t\t %f\n", iteration, x0, x1, x2, f2);
            x0 = x1;
            f0 = f1;
            x1 = x2;
            f1 = f2;

            f2 = f(x2);

            iteration++;

            if (iteration > N)
            {
                printf("The solution doesn't converge within %d iterations.\n", N);
                break; // Exit the loop if the maximum number of iterations is reached
            }
        }

    } while (fabs(f2) > e);

    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("\nThe approximate solution is: %0.8f\n", x1);

    return 0;
}
