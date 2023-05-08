#include<stdio.h>

int n,w[10][10];

void readGraph()
{
	FILE *fp;
	fp=fopen("graph.txt","r");
	if(fp==NULL)
	{
		printf("File open failed\n");
		return;
	}
	fscanf(fp,"%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp,"%d",&w[i][j]);
		}
	}
	fclose(fp);
}

void showGraph()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%3d",w[i][j]);
		}
		printf("\n");
	}
}

int dist[10];
int pred[10];
int sptSet[10];

int mindist(){
	int min=9999;
	int minIndex=-1,i;
	for(i=0;i<n;i++)
	{
		if(sptSet[i]==0)
		{
			if(min>dist[i])
			{
				min=dist[i];
				minIndex=i;
			}
		}
	}
	return minIndex;
}

void Dijkstra(int r)
{
	int i,v;
	for(i=0;i<n;i++)
	{
		dist[i]=9999;
		pred[i]=-1;
		sptSet[i]=0;
	}
	dist[r]=0;
	for(i=0;i<n;i++)
	{
		int u=mindist();
		sptSet[u]=1;
		for(v=0;v<n;v++)
		{
			if(w[u][v]!=0){
				if(sptSet[v]==0 && dist[u]+w[u][v]<dist[v])
				{
					dist[v]=dist[u]+w[u][v];
					pred[v]=u;
				}
			}
		}
	}
}


void showPath(int dest){
	if(dest==-1) return;
	else{
		showPath(pred[dest]);
		printf("%4c",dest+'A');
	}
}

void showTree(){
	int i;
	for(i=0;i<n;i++)
	{
		if(pred[i]!=-1)
		printf("%c->%c,%d\n",pred[i]+'A',i+'A',w[pred[i]][i]);
	}
}


int main(){
	readGraph();
	showGraph();
	Dijkstra(0);
	for(int i=1;i<n;i++){
		printf("Path from A to %c ->",i+'A');
		showPath(i);
		//printf("\n");
		printf("\tCost=%d\n",dist[i]);
	}
	return 0;
}
