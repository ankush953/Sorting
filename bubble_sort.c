#include <stdio.h>
#include <malloc.h>

int main()
{
        int *a,n,t,i,j;
        printf("Enter the number of elements => ");
        scanf("%d",&n);

        a=(int *)malloc(sizeof(int)*n);

        printf("Enter elements => ");
        for(i=0; i<n; i++)
                scanf("%d",a+i);

        for(i=0; i<n-1; i++)
        {
                for(j=0; j<n-i; j++)
                {
                        if(a[j]>a[j+1])
                        {
                                t = a[j];
                                a[j] = a[j+1];
                                a[j+1] = t;
                        }
                }
        }
        printf("After sorting \n");
        for(i=0; i<n; i++)
                printf("%d ",*(a+i));
        return 0;
}
