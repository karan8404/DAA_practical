#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int i, j, k;

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + j + 1];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = (l + r) / 2;

        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d,", arr[i]);
}

int main()
{
    int arr[] = {5, 2, 19, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    print(arr, n);

    sort(arr, 0, n - 1);

    printf("\nSorted array is \n");
    print(arr, n);
}