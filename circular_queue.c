//  I am implementing circular_queue using an array
# include<stdio.h>
# define max 5

 // 1->2->3->4
int count = 0;
void insert(int *list,int data ,int *front ,int *rear)
	{
		// count++;
		// printf("count %d\n",count);
		if(*front == 0 && *rear == max-1 || *rear == *front-1)
			printf("overflow Dude try deleting some elements\n");
		else
			{
				if(*front ==-1 && *rear == -1)
					{
						*front = *rear = 0;
						list[*rear] = data;
						// printf("empty so creating one\n");
					}
				else if(*rear == max-1)
					{
						*rear = 0;
						list[*rear] = data;
						// printf("Rear is end but fron not on 0\n");
					}
				else
					{
						(*rear)++;
						// printf("incrementing rear\n");
					}
				list[*rear] = data;
				// printf("%d inseted list at index %d\n",list[*rear],*rear );
				printf("%d is front ----- %d is rear\n",*front,*rear );
			}
	}

void dele(int *list , int *front , int *rear)
	{
		if (*front == -1 || *rear == -1)
			{
				printf("Underflow in queue \n");
			}
		else
			{
				printf("Deleting %d\n",list[*front]);
				list[*front] = 0;
				if(*front ==0 && *rear == 0 || *front==*rear)
					{	
						*front = *rear = -1;
					}
				else if(*front == max-1)
					{
						*front = 0;
					}
				else
					(*front)++;

				printf("%d is front ----- %d is rear\n",*front,*rear );
			}
		printf("delted\n");
	}
void display(int *list ,int *front , int *rear)
	{
		// printf("Displaying Elements\n");
		for (int i = *front ; i<=*rear ;++i)
			{
				printf("%d of index %d \n",list[i],i);
			}
	}


int main(){
	int circular_queue[max];
	int front ,rear,data;
	int ch = 1,loop;
	front = rear = -1;
	// printf("welcome man\n");
	do
		{
			printf("Enter Choice\n");
			scanf("%d",&ch);
			switch(ch)
				{
					case 1:
						printf("Enter the data :\n");
						scanf("%d",&data);
						insert(circular_queue,data,&front,&rear);
						break;
					case 2:
						dele(circular_queue,&front,&rear);
					case 3:
						display(circular_queue,&front,&rear);

				}
			printf("Do you wanna continue\n");
			scanf("%d",&loop);
		}while(loop!=0);


	
	

	return 0;
}



