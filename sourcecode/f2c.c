#include <stdio.h>

main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%5s %8s\n", "fahr", "celsius");
    while (fahr <= upper) {
        celsius = 5.0 * (fahr-32.0) /9.0;
        printf("%5.0f %8.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    printf("%d\n", EOF);
}