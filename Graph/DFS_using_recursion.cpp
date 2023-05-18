#include<iostream>
#include<stdio.h>
using namespace std;

int n;
int G[10][10];
int visited[10]={0};

void readGraph() {
    FILE *fp;
    fp=fopen("graph_data.txt","r");
    if(fp==NULL) {
        cout<<"File openning error!"<<endl;
        return;
    }
    fscanf(fp,"%d",&n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            fscanf(fp,"%d",&G[i][j]);
        }
    }
}

void DFS(int v){
    visited[v]=1;
    printf("%-3c",v+'A');
    for(int i=0;i<n;i++) {
        if(G[v][i]==1) {
            if(visited[i]==0)
                DFS(i);
        }
    }
    
}

void displayGraph() {
	printf("   ");
	for(int j=0;j<n;j++)
			printf("%-3c",j+'A');
	cout<<endl;
	for(int i=0;i<n;i++) {
		printf("%-3c",i+'A');
		for(int j=0;j<n;j++) {
			printf("%-3d",G[i][j]);
		}
		cout<<endl;
	}
}

int main() {
    readGraph();
    cout<<"Adjacency Matrix = "<<endl;
    displayGraph();
    cout<<"DFS = ";
    DFS(0);
}