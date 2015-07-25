/*
*	To create a graph using array.
*	author: clark zhang
*	date: 2015/07/23
*/
#include <stdio.h>
#include <string.h>

#define MAX_VERTEX_NUM 10	
#define MAX_NAME 5	
#define MAX_INIT 65535
typedef int VRType;
typedef char VertexType[MAX_NAME];
typedef enum{DG, DN, UDG, UDN} GraphKind;

typedef struct ArcCell{
	VRType adj;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];	
	AdjMatrix arcs;			
	int vexnum,arcnum;	
	GraphKind kind;
}Graph;

int Locate(Graph *g, VertexType v){
	int i;
	for(i=0; i<g->vexnum; i++){
		if(strcmp(v, g->vexs[i]) == 0)
			return i;
	}
	return -1;
}

void CreateUDG(Graph *G)  
{  
    int         i, j, k;  
    VertexType  va, vb;  
		
	printf("Input the number of the vertex and arc:\n");
	scanf("%d %d",&G->vexnum, &G->arcnum);
	printf("input the name of the vertex:\n");
	for(i=0; i<G->vexnum; i++)
		scanf("%s",G->vexs[i]);
    for (i = 0; i < G->vexnum; ++i)          
        for (j = 0; j < G->vexnum; ++j)  
        {  
            G->arcs[i][j].adj  = 0;   
        }  
    for (k = 0; k < G->arcnum; ++k)  
    {  
		printf("\nInput the first vertex:\n");
        scanf("%s",va);
        i = Locate(G, va);  
        printf("\nInput the last vertex:\n");
		scanf("%s",vb);
		j = Locate(G, vb);  
        G->arcs[i][j].adj = G->arcs[j][i].adj = 1;     
    }  
    G->kind = UDG;  
} 
void CreateDN(Graph *G){
	printf("Create the Digraph Net:\n");
	int i,j,k;
	VertexType va,vb;
	printf("Please input the vertexnum and the arcnum:\n");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	for(i=0;i<G->vexnum;i++){
		for(j=0;j<G->vexnum;j++){
			G->arcs[i][j].adj = MAX_INIT;
		}
	}
	printf("\nInput the name of the vertex:\n");
	for(i=0;i<G->vexnum;i++){
		scanf("%s",G->vexs[i]);
	}
	for(k=0;k<G->arcnum;k++){
		printf("\nInput the first vertex:\n");
		scanf("%s",va);
		i = Locate(G, va);
		printf("\nInput the second vertex:\n");
		scanf("%s",vb);
		j = Locate(G, vb);
		printf("\nInput the weight of the vector:\n");
		VRType m;
		scanf("%d",&m);
		G->arcs[i][j].adj = m;
	}
	G->kind = DN;
}
void ShowGraph(Graph g){
	printf("\nThe Graph is show as belows:\n");
	int i,j;
	for(i=0;i<g.vexnum;i++){
		for(j=0;j<g.vexnum;j++){
			printf("%10d",g.arcs[i][j].adj);
		}
		printf("\n");
	}
}
void CreateGraph(Graph *G){
	printf("Create the Adjacency List:\n");
	printf("Please input the kind of the tree:\n");
	scanf("%ud",&G->kind);
	switch(G->kind){
		case UDG:
			CreateUDG(G);
			break;
		case DN:
			CreateDN(G);
			break;
		default:
			printf("Must be one of UDG, UDN, DG, DN");
			break;
	}
}
int main(int argc, char **argv)
{
	Graph g;
	CreateGraph(&g);
	ShowGraph(g);
	return 0;
}

