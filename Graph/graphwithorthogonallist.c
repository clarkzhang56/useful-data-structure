/*
*	To create a graph using orthogonal list.
*	author: clark zhang
*	date: 2015/07/26
*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_NUM 5
#define MAX_VEX_NUM 20

typedef char VexType[MAX_NUM]; //the type of vextex name is char

typedef struct AcrBox{			//the node of the arc
	int tailvex,headvex;      //the arc is from the tailvex to headvex
	struct AcrBox *hlink;     //the arc has the same head
	struct AcrBox *tlink;
	int weight;               //the weight of the arc
}ArcBox;
typedef struct VexNode{			//the node of the vextex
	VexType data;
	ArcBox *firstin;          //the arc whoes headvex is the data
	ArcBox *firstout;         //the arc whoes tailvex is the data
}VexNode;
typedef struct {
	VexNode xlist[MAX_VEX_NUM];
	int vexnum, arcnum;
}GraphDN;
int Locate(GraphDN *G, VexType vt){
	int i;
	for(i=0; i<G->vexnum; i++){
		if(strcmp(G->xlist[i].data, vt) == 0){
			return i;
		}
	}
	return -1;
}
void CreateDNgraph(GraphDN *G){
	int i,j,k;
	VexType tail,head;
	printf("Creating the Diagraph Net with orthogonal list......\n");
	printf("Input the num of the vextex and arc:\n");
	scanf("%d %d",&G->vexnum, &G->arcnum);
	printf("Input the vextex name:\n");
	for(i=0; i<G->vexnum; i++){
		scanf("%s",G->xlist[i].data);
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}
	for(k=0; k<G->arcnum; k++){
		printf("Input the tailvex name:\n");
		scanf("%s",tail);
		printf("Input the headvex name:\n");
		scanf("%s",head);
		i = Locate(G, tail);
		j = Locate(G, head);
		if(i != -1 && j != -1){
			ArcBox *arcbox = (ArcBox *)malloc(sizeof(ArcBox));
			arcbox->tailvex = i;
			arcbox->headvex = j;
			printf("Input the weight:\n");
			scanf("%d",&arcbox->weight);
			/* I can't add at the end of the list, but I can add at the begin and it's more easier this way */
			arcbox->tlink = G->xlist[i].firstout;
			G->xlist[i].firstout = arcbox;
			arcbox->hlink = G->xlist[j].firstin;
			G->xlist[j].firstin = arcbox;
		}else{
			printf("What you write is not vextex's name. Please try again!\n");
			--k;
		}
	}
}
void ShowGraph(GraphDN *G){
	int i;
	ArcBox *tmpin, *tmpout;
	printf("Show the graph:\n");
	for(i=0; i<G->vexnum; i++){
		printf("%5s",G->xlist[i].data);
		printf(" out: ");
		if(G->xlist[i].firstout == NULL){
			printf(" NULL ");
		}else{
			tmpout = G->xlist[i].firstout;
			while(tmpout != NULL){
				printf("%5d%5d%5d     ",tmpout->tailvex,tmpout->headvex,tmpout->weight);
				tmpout = tmpout->tlink;
			}
		}
		printf(" in: ");
		if(G->xlist[i].firstin == NULL){
			printf(" NULL ");
		}else{
			tmpin = G->xlist[i].firstin;
			while(tmpin != NULL){
				printf("%5d%5d%5d",tmpin->tailvex,tmpin->headvex,tmpin->weight);
				tmpin = tmpin->hlink;
			}
		}
		printf("\n");
	}
}
int main(int argc, char **argv)
{
	GraphDN graph;
	CreateDNgraph(&graph);
	ShowGraph(&graph);
	
	return 0;
}
