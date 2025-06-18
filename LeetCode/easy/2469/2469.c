#include <stdlib.h>

double* convertTemperature(double celsius, int* returnSize) 
{
    double Kelvin = celsius + 273.15;
    double Fahrenheit = celsius * 1.80 + 32.00;
    double *ans = (double *)malloc(sizeof(double) * 2);
    ans[0] = Kelvin;
    ans[1] = Fahrenheit;
    if (returnSize != NULL)
        *returnSize = 2;
    return ans;
}

#include <stdio.h>
int main()
{
    int returnSize = 0;
    double *ans01 = convertTemperature(36.50, &returnSize);
    double *ans02 = convertTemperature(122.11, &returnSize);

    printf("%.5f, %.5f\n", ans01[0], ans01[1]);
    printf("%.5f, %.5f\n", ans02[0], ans02[1]);

    free(ans01);
    free(ans02);

    return 0;
}