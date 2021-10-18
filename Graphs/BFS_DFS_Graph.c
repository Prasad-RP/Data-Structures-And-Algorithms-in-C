/*Indegree,Outdegree,total degree of each vertex and,
  BFS , DFS on a graph represented using adjacency matrix*/
#include<stdio.h>
#define MAX 10

typedef struct Q
{
	int Rear,Front;
	int data[MAX];
}Q;

int empty(Q *P);
int full(Q *P);
void enqueue(Q *P,int x);
int dequeue(Q *P);
void BFS(int);
void DFS(int);
void degrees();
int G[MAX][MAX];
int n=0;
int visited[MAX];

void create()
 {
        int i,j;
	printf("\nEnter no of vertices : ");
	scanf("%d",&n);
	printf("\nEnter the adjecendy matrix of  graph : ");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);

 }


int main()
{
	int i,j,v,op;

	do{
	   printf("\n1)Read the graph");
	   printf("\n\n2)DFS\n3)BFS\n4)Indegree/Outdegree/Total degree\n5)QUIT");
	   printf("\nEnter Your choice : ");
	   scanf("%d",&op);
	   switch(op)
	    {
	      case 1:create();break;
	      case 2:printf("\nEnter the starting vertex for DFS : ");
		     scanf("%d",&v);
		     for(i=0;i<n;i++)
			   visited[i]=0;
		     DFS(v);
		     break;
	      case 3:printf("\nEnter the starting vertex for BFS : ");
		     scanf("%d",&v);
		     BFS(v);break;

	      case 4: degrees();break;

	    }
	  }while(op!=5);

}

void BFS(int v)
{
	int visited[MAX],i;
	Q q;
	q.Rear=q.Front=-1;
	for(i=0;i<n;i++)
	  visited[i]=0;
	enqueue(&q,v);
	printf("\n visit\n",v);
	visited[v]=1;
	while(!empty(&q))
	{
		v=dequeue(&q);
		// visit and add adjecency vertices
		for(i=0;i<n;i++)
			if(visited[i]==0 && G[v][i]!=0)
			{
				enqueue(&q,i);
				visited[i]=1;
				printf("\n%d",i);
			}
	}
}

int empty(Q *P)
{
	if(P->Rear==-1)
		return(1);
	return(0);
}

int full(Q *P)
{
	if(P->Rear==MAX-1)
		return(1);
	return(0);
}

void enqueue(Q *P,int x)
{
	if(P->Rear==-1)
	{
		P->Rear=P->Front=0;
		P->data[P->Rear]=x;
	}
	else
	{
		P->Rear=P->Rear+1;
		P->data[P->Rear]=x;
	}
}

int dequeue(Q *P)
{
	int x;
	x=P->data[P->Front];
	if(P->Rear==P->Front)
	{
		P->Rear=-1;
		P->Front=-1;
	}
	else
		P->Front=P->Front+1;
	return(x);
}

void DFS(int i)
{
	int j;
	printf("\n%d",i);
	visited[i]=1;
	for(j=0;j<n;j++)
		if(!visited[j] && G[i][j]==1)
			DFS(j);
}
void degrees()
 {
	int indegree,outdegree,i,j;
	for(i=0;i<n;i++)
	 {
		indegree=outdegree=0;
		for(j=0;j<n;j++)
		  {
			if(G[i][j]!=0)
				outdegree++;
			if(G[j][i]!=0)
				indegree++;
		  }
		printf("\nvertex : %d\tIndegree :%d\tOut degree:%d\tTotal Degree:%d",i,indegree,outdegree,indegree+outdegree);
	 }
 }



