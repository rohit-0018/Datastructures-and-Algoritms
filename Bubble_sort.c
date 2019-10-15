// This program impliments Bubble sort a sorting technique
// The basic idea of bubble sort is to swap the adjacent element if it is smaller
//  8 2 3 1 5 2 39 -> step 1 : 2 8 3 1 5 2 39
// 					  step 2 : 2 8 1 3 5 2 39 and so ...............

# include<stdio.h>

void bubble_sort(int *a,int n)
	{
		int no_swap_flag = 0,temp;
		for(int i=0;i<n-2;++i)
			{
				no_swap_flag = 0;
				for(int j=0;j<n-i-1;++j)
					{
						if(a[j]>a[j+1])
							{
								temp = a[j];
								a[j] = a[j+1];
								a[j+1] = temp;
							}
						else
							no_swap_flag = 1;
					}
			}
	}

int main()
	{
		int arr[] = {8,2,3,1,5,4,6,7,1,2,3,24,4,33,54,54,6,6,56,7,6,6},size;
		size = sizeof(arr)/sizeof(int);
		printf("------The  array is-----\n");
		for (int i=0;i<size;++i)
			{
				printf("%d ",arr[i]);
			}
		printf("\n");
		bubble_sort(arr,size);
		printf("------The sorted array is-----\n");
		for (int i=0;i<size;++i)
			{
				printf("%d",arr[i]);
			}

		return 0;
	}