#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d,", &arr[i]);
    }

    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (n == 5)
    {
        int avg = sum / n;
        printf("%d", avg);
    }

    if (n == 6)
    {
        float avg = sum / n;
        printf("%.1f", avg);
    }

    return 0;
}
