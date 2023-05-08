#include<stdio.h>
#include<iostream>
using namespace std;

int n,w[10][10];

void readGraph(){
	FILE *fp;
	fp=fopen("graph.txt","r");
	if(fp==NULL){
		printf("File open failed\n");
		return;
	}
	fscanf(fp,"%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fscanf(fp,"%d",&w[i][j]);
		}
	}
	fclose(fp);
}

void showGraph(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d",w[i][j]);
		}
		printf("\n");
	}
}

int key[10];
int parent[10];
int mstSet[10];

int minKey(){
	int min=9999;
	int minIndex=-1,i;
	for(i=0;i<n;i++){
		if(mstSet[i]==0){
			if(min>key[i]){
				min=key[i];
				minIndex=i;
			}
		}
	}
	return minIndex;
}

void Prims(int r){
	int i,v;
	for(i=0;i<n;i++){
		key[i]=9999;
		parent[i]=-1;
		mstSet[i]=0;
	}
	key[r]=0;
	for(i=0;i<n;i++){
		int u=minKey();
        cout<<u<<endl;
		mstSet[u]=1;
		for(v=0;v<n;v++){
			if(w[u][v]!=0){
				if(mstSet[v]==0 && key[v]>w[u][v]){
					key[v]=w[u][v];
					parent[v]=u;
				}
			}
		}
	}
    for(i=0;i<n;i++){
		if(parent[i]!=-1)
		printf("%c->%c\t%d\n",parent[i]+'A',i+'A',w[parent[i]][i]);
	}
}



int main(){
	readGraph();
	showGraph();
	Prims(0);
	return 0;
}