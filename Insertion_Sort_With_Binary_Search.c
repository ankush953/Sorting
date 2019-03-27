# include <stdio.h>

int binary_pos(int array[],int low,int high,int key)
{
        int mid;

        // pos stores index of element less than or equal to key.
        // initially it is initialized to -1
        int pos = -1;
        while(low<=high)
        {
                mid = (low+high)/2;
                if(array[mid]<=key )
                {
                        pos = mid;
                        low = mid+1;
                }
                else
                        high = mid-1;
        }
        return pos;
}

void insertion_sort(int array[],int n)
{
        int key,pos,i,j,k;
        for(i=0; i<n; i++)
        {
                pos = binary_pos(array,0,i-1,array[i]);
                
                key = array[i];
                for(j=i-1; j>pos; j--)
                        array[j+1] = array[j];
                array[j+1] = key;

        }
}

void printArray(int *array,int n)
{
        for(int i=0; i<n; i++)
                printf("%d ",array[i]);
        printf("\n");
}

int main(void)
{
        int n,i;
        printf("Enter number of Elements : " );
        scanf("%d",&n);
        int array[n];
        printf("Enter array Elements : " );
        for(i=0; i<n; i++)
                scanf("%d",array+i);

        printf("Arry Before sorting\n");
        printArray(array,n);

        insertion_sort(array,n);
        printf("Array After Sorting\n");
        printArray(array,n);
        return 0;
}
