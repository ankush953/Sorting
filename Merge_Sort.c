//merge sort
#include <stdio.h>

void merge(int array[], int low, int mid, int high)
{
    // declare temporary array of sufficient size to store elements of array
    int i = low, j = mid + 1, k = low, temp[50];

    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= high)
        temp[k++] = array[j++];
    for (i = 0; i <= high; i++)
        array[i] = temp[i];
}

void mergesort(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(array, low, mid);
        mergesort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

int main()
{
    int n;

    // n is number of elements in array
    scanf("%d", &n);

    // create array of size n
    int array[n];

    // take input array
    for (int i = 0; i < n; i++)
        scanf("%d", array + i);

    // Calling mergesort function
    mergesort(array, 0, n);

    // print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);

    return 0;
}
