//heap sort
#include <stdio.h>

void adjust(int array[], int curr, int n)
{
        // This function will compare value at an index with its left and right child
        // and will keep max of all three values at current index
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        int temp;
        int max = curr;
        if (left < n && array[max] < array[left])
                max = left;
        if (right < n && array[max] < array[right])
                max = right;

        // If curr element is maximum of all its left and right child then no need 
        // to exchange and balance further
        if (max != curr)
        {
                temp = array[max];
                array[max] = array[curr];
                array[curr] = temp;
                adjust(array, max, n);
        }
}

void maxheapify(int array[], int n)
{
        // This function will create maxheap i.e. for each valid index and its left 
        // and right index array[curr] > array[left] && array[curr] > array[right]
        int i;
        for (i = n / 2; i > -1; i--)
                adjust(array, i, n);
}

// This function will keep putting the max element at current
// last index and
void heapsort(int array[], int n)
{
        int i, temp;
        maxheapify(array, n);
        for (i = n - 1; i > -1; i--)
        {
                temp = array[0];
                array[0] = array[i];
                array[i] = temp;
                adjust(array, 0, i - 1);
        }
}

int main(void)
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
        heapsort(array, n);

        // print sorted array
        for (int i = 0; i < n; i++)
                printf("%d ", array[i]);

        return 0;
}
