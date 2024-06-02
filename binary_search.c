#include <stdio.h>

int bin_search(int arr[], int n, int x)
{
    int l = 0, r = n - 1;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;

        if (x < arr[mid])
            r = mid - 1;
        else if (x == arr[mid])
            return (mid);
        else
            l = mid + 1;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 9;
    int result = bin_search(arr, n, x);
    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", result);
}