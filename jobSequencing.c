#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Job
{
    char id;
    int deadline;
    int profit;
};

void printJob(struct Job job)
{
    printf("%c : %d\n", job.id, job.profit);
}

int compare(const void *a, const void *b)
{
    struct Job *x = (struct Job *)a;
    struct Job *y = (struct Job *)b;
    return y->profit - x->profit;
}

int getmaxDead(struct Job arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].deadline > max)
            max = arr[i].deadline;
    }
    return max;
}

void schedule(struct Job arr[], int n)
{
    qsort(arr, n, sizeof(struct Job), compare);
    int maxDeadline = getmaxDead(arr, n);
    int i;

    char slots[maxDeadline];
    for (i = 0; i < maxDeadline; i++)
        slots[i] = '*';

    int filled = 0;
    i = 0;
    while (filled < maxDeadline)
    {
        if (i >= n)
            break;
        if (filled < arr[i].deadline)
        {
            for (int k = 1; arr[i].deadline - k >= 0; k++)
            {
                if (slots[arr[i].deadline - k] != '*')
                    continue;
                slots[arr[i].deadline - k] = arr[i].id;
                filled++;
                break;
            }
        }
        i++;
    }

    for (i = 0; i < maxDeadline; i++)
        printf("%c", slots[i]);
}

int main()
{
    struct Job arr[] = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};
    int n = sizeof(arr) / sizeof(struct Job);

    schedule(arr, n);
}