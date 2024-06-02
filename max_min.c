#include <stdio.h>

int max(int arr[], int n)
{
    int i;
    int max = 0;
    for (i = 1; i < n; i++)
        if (arr[i] > arr[max])
            max = i;
    return max;
}

int min(int arr[], int n)
{
    int i;
    int min = 0;
    for (i = 1; i < n; i++)
        if (arr[i] < arr[min])
            min = i;
    return min;
}

int main()
{
    int arr[] = {5,15,6,19,100};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maximum = max(arr, n);
    int mininimum = min(arr, n);

    printf("Maximum is %d\n", arr[maximum]);

    printf("Minimum is %d\n", arr[mininimum]);
}