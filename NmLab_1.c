// HEADER FILE
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (3 * x - cos(x) - 1)
#define df(x) (3 + sin(x))

int main()
{
    float x0, e, f0, x1, df0, f1;
    int iteration = 1, N;

    printf("\nEnter the value of initial guess (x0), predefined error(e), maximum no of iteration(N): \t");
    scanf("%f %f %d", &x0, &e, &N);

    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("Iteration \t\t x0 \t\t\t f(x0) \t\t\t x1 \t\t\t f(x1) ");
    printf("\n------------------------------------------------------------------------------------------------------------\n");

    do
    {
        f0 = f(x0);
        df0 = df(x0);

        if (df0 == 0)
        {
            printf("Mathematical error.\n");
            break; // Exit the loop in case of mathematical error
        }
        else
        {

            x1 = x0 - (f0 / df0);
            f1 = f(x1);

            printf("%d \t\t\t %f \t\t %f \t\t %f \t\t %f\n", iteration, x0, f0, x1, f1);
            x0 = x1;

            iteration++;

            if (iteration > N)
            {
                printf("The solution doesn't converge within %d iterations.\n", N);
                break; // Exit the loop if the maximum number of iterations is reached
            }
        }

    } while (fabs(f1) > e);

    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("\nThe approximate solution is: %0.8f\n", x1);

    return 0;
}
