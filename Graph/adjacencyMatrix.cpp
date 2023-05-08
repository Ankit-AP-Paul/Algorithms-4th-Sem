#include<bits/stdc++.h>
using namespace std;

int main() {
	FILE *fp;
	fp=fopen("graph_data.txt","r");
	if(fp==NULL) {
		cout<<"Error to open file"<<endl;
		return 0;
	}
	int v;
	fscanf(fp,"%d",&v);
	int **adjM=new int*[v];
	for(int i=0;i<v;i++) {
		adjM[i]=new int[v];
		for(int j=0;j<v;j++) {
			fscanf(fp,"%d",&adjM[i][j]);
		}
	}
	int totDegree=0;
	cout<<"Adjacency Matrix = "<<endl;
	printf("   ");
	for(int j=0;j<v;j++)
			printf("%-3c",j+'A');
	cout<<endl;
	for(int i=0;i<v;i++) {
		printf("%-3c",i+'A');
		for(int j=0;j<v;j++) {
			if(adjM[i][j]==1)
				totDegree++;
			printf("%-3d",adjM[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Total degree of graph = "<<totDegree<<endl;
	cout<<endl;
	cout<<"Number of edges = "<<(totDegree/2)<<endl;
	cout<<endl;
	char ch;
	cout<<"Enter the vertex...";
	cin>>ch;
	int n=ch-'A';
	cout<<"Adjacent vertices of "<<ch<<" = ";
	for(int i=0;i<v;i++) {
		if(adjM[n][i]==1)
			printf("%-3c",i+'A');
	}
	cout<<endl;
	return 0;
}
