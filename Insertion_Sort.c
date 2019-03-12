#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int *a,int n)
{
    int i,j,key;
    for(j=1;j<n;j++)
    {
        key = a[j];
        i = j-1;
        while(key<a[i] && i > -1)
        {
            a[i+1] = a[i];
            i -= 1;
        }
        a[i+1] = key ;
    }
}

int main()
{
    int n,*p=NULL;
    scanf("%d",&n);
    p = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",p+i);
    printf("Before insertion sort : ");
    for(int i=0;i<n;i++)
        printf("%d ",*(p+i));
    insertion_sort(p,n);
    printf("\nAfter insertion sort : ");
    for(int i=0;i<n;i++)
        printf("%d ",*(p+i));
    return 0;
}
