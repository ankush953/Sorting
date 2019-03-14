#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array, n, temp, i, j, min;

    printf("Enter the number of elements => ");
    scanf("%d", &n);

    array = (int *)malloc(sizeof(int) * n);

    printf("Enter elements => ");
    for (i = 0; i < n; i++)
        scanf(" %d", array + i);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array[j] < array[i])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printf("After sorting \n");
    for (i = 0; i < n; i++)
        printf("%d ", *(array + i));
    return 0;
}
