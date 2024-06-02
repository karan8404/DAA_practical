#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int sort(int values[], int p[], int wt[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] > values[i])
            {
                swap(values, i, j);
                swap(p, i, j);
                swap(wt, i, j);
            }
        }
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d,", arr[i]);
    printf("\n");
}

int main()
{
    int W = 50;
    int n = 3;
    int p[] = {60, 100, 120};
    int wt[] = {10, 20, 30};

    int values[n];
    for (int i = 0; i < n; i++)
        values[i] = p[i] / wt[i];

    sort(values, p, wt, n);

    print(values, n);
    print(wt, n);
    print(p, n);

    float maxProfit = 0.0f;
    int i = 0;
    while (W > 0)
    {
        if (W > wt[i])
            maxProfit = maxProfit + p[i];

        else
            maxProfit = maxProfit + p[i] * (W / (float)wt[i]);

        W = W - wt[i];
        i++;
    }
    printf("%.2f", maxProfit);
}