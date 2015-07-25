/*
*	To create a graph using adjacency list.
*	author: clark zhang
*	date: 2015/07/25
*/
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_VEXTEX 10
#define MAX_LEN 5

typedef enum{UDG,UDN,DG,DN} GraphKind;
typedef char VertexType[MAX_LEN];	//the kind of the vertex's name
typedef struct ArcNode{				//the struct of the arc
	int adjvex;
	struct ArcNode *nextArc;
	int weight;
}ArcNode;
typedef struct VNode{				//the struct of the head
	VertexType data;
	ArcNode *firstArc;
}VNode,AdjList[MAX_VEXTEX];
typedef struct Graph{
	int vertexnum,arcnum;
	AdjList vertices;
	GraphKind kind;
}Graph;
/*	To find the locate of the vertex in the graph	*/
int Locate(Graph *g, VertexType vt){
	int i;
	for(i=0;i<g->vertexnum;i++){
		if(strcmp(g->vertices[i].data, vt) == 0){
			return i;
		}
	}
	return -1;
}
void CreateDN(Graph *G){
	printf("Create the Digraph Net:\n");
	int i,j,k;
	VertexType vf,vl;
	printf("Please input the vextexnum and the arcnum:\n");
	scanf("%d %d",&G->vertexnum,&G->arcnum);
	printf("Please input the name of the vertex:\n");	
	for(i=0;i<G->vertexnum;i++){
		scanf("%s",G->vertices[i].data);
		G->vertices[i].firstArc = NULL;
	}
	for(k=0;k<G->arcnum;k++){
		printf("Please input the first vertex:\n");
		scanf("%s",vf);
		printf("Please input the last vertex:\n");
		scanf("%s",vl);
		i = Locate(G,vf);
		j = Locate(G,vl);
		if(i != -1 && j != -1){
			ArcNode *tmp = (ArcNode*) malloc (sizeof(ArcNode));
			tmp->adjvex = j;			
			printf("Please input the weight:\n");
			scanf("%d",&tmp->weight);
			if(G->vertices[i].firstArc == NULL){	//to decide whether the head has the firstarc
				G->vertices[i].firstArc = tmp;
				G->vertices[i].firstArc->nextArc = NULL;
			}else{									//if the firstarc has nextarc
			/*
			 *	Below is very important. I want to modify the address of the memory on G->vertices[i].firstArc.
			 *  So I have to use the double pointer to do it. If I just use one pointer, I can change what it 
			 * point to but I can't change it's address.
			 */
				ArcNode **tmpnextarc = &G->vertices[i].firstArc->nextArc;
				while(*tmpnextarc != NULL){
					*tmpnextarc = (*tmpnextarc)->nextArc;
				}
				*tmpnextarc = tmp;
				(*tmpnextarc)->nextArc = NULL;
			}
			//free(tmp);				You must rememver that the you can't free the memory when it's used.
		}
	}
	G->kind = DN;
}
void ShowGraph(Graph *g){
	int i;
	printf("\nThe %d Graph is show as belows:\n",g->kind);
	for(i=0; i<g->vertexnum; i++){
		printf("%5s ",g->vertices[i].data);
		if(g->vertices[i].firstArc != NULL){
			ArcNode *tmpnode = g->vertices[i].firstArc;
			while(tmpnode != NULL){
				printf(" %d weight: %d",tmpnode->adjvex,tmpnode->weight);
				tmpnode = tmpnode->nextArc;				
			}
			free(tmpnode);
		}else{
			printf(" It's empty!");
		}
		printf("\n");
	}
}
void CreateGraph(Graph *G){
	printf("Create the Adjacency List:\n");
	printf("Please input the kind of the list:\n");
	scanf("%ud",&G->kind);
	switch(G->kind){
		case DN:
			CreateDN(G);
			break;
		default:
			printf("Must be one of UDG, UDN, DG, DN");
			break;
	}
}
int main()
{
	Graph mygraph;
	CreateGraph(&mygraph);
	ShowGraph(&mygraph);
	return 0;
}

