#include <stdio.h>
#include "malloc.h"
/*
*Create a linklist without order
*/
typedef struct linklist{
	struct linklist *next;
	int value;
}Link;
void insert(Link *link, int a){
	//insert to the end of the linklist
	while(link->next != NULL){
		link = link->next;
	}
	Link *tmp = (Link*)malloc(sizeof(Link));
	tmp->value = a;
	tmp->next = NULL;
	link->next = tmp;
}
void CreateLink(Link **mylink, int a[], int n){
	*mylink = (Link*)malloc(sizeof(Link));
	(*mylink)->value = a[0];
	(*mylink)->next = NULL;
		int i;
	for(i=1; i<n; i++){
		insert((*mylink),a[i]);
	}
}
void showlink(Link *link){
	//to show the linklist
	printf("\n");
	while(link!=NULL){
		printf("%d ",link->value);
		link = link->next;
	}
}
void deletelink(Link *link, int a){
	if(link->value == a){
		//if the linklist has only the rootnode
		link = NULL;
		free(link);
		return ;
	}
	while(link->next->value != a){
		link = link->next;
		if(link->next == NULL) {
			printf("\nNo value in the link!\n");
			return ;
		}
	}
	Link *tmp = link->next;
	link->next = tmp->next;
	tmp = NULL;
	free(tmp);
}
void destroylink(Link *link){
	while(link != NULL){
		Link *tmp = link;
		link = link->next;
		tmp = NULL;
		free(tmp);
	}
}
int main(int argc, char **argv)
{
	//below is just a simple test
	printf("hello world\n");
	int a[]={4,2,5,3,1,8};
	int n = sizeof(a)/sizeof(int);
	Link *mylink;
	CreateLink(&mylink, a, n);
	showlink(mylink);
	int b = 9;
	insert(mylink, b);
	showlink(mylink);
	int c = 7;
	deletelink(mylink, c);
	showlink(mylink);
	destroylink(mylink);
	return 0;
}

