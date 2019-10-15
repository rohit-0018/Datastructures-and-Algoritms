#include<stdio.h>
#include<stdlib.h>
typedef struct node new;

struct node{
	int data;
	struct node *next;
};

struct node* newnode(int data){
	struct node *new_node = (struct node*)(malloc(sizeof(struct node)));
	new_node->data = data;
	new_node->next = 0;
	return new_node;
}
void display_ll(struct node* head){
	struct node *temp;
	temp = head;
	while(1){
		if(temp->next == NULL){
			printf("%d breaking\n",temp->data);
			break;	
		}
		else{
			printf("%d \n",temp->data);
			temp = temp->next;
		}

	}

	printf("Displaying complete\n");
}

new * insertion(struct node *head){
	int data,i = 0;
	while(i<10)
		{
			if(head == 0){
				head = newnode(i);
			}
			else{
				new *temp = head;
				while(1){
					if(temp->next==0){
						break;
					}
					temp = temp->next;
				}
				temp->next  = newnode(i);
			}
			i++;
		}
	
	return head;
	}


void main(){
	struct node *head = 0;
	int i = 0;
	printf("%p\n", &head);
	int count = 1;
	head = insertion(head);
	if(head)
	{
		display_ll(head);

	}
	else
		{

			printf("empty so nothing to show\n");
		}

}// Main closing braces	
