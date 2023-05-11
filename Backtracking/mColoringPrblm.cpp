#include<bits/stdc++.h>
using namespace std;

int x[10];
int n,col;
int G[10][10];

void readGraph() {
	FILE *fp;
	fp=fopen("graph.txt","r");
	if(fp==NULL) {
		cout<<"File openning error"<<endl;
		return ;
	}
	fscanf(fp,"%d",&n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			fscanf(fp,"%d",&G[i][j]);
		}
	}
}

void displayGraph() {
    printf("   ");
    for(int i=0;i<n;i++) {
        printf("%-3c",i+'A');
    }
    cout<<endl;
	for(int i=1;i<=n;i++) {
        printf("%-3c",i-1+'A');
		for(int j=1;j<=n;j++) {
			printf("%-3d",G[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
}

void displaySoln(int x[]) {
	for(int i=1;i<=n;i++)
		cout<<"C"<<x[i]<<"  ";
	cout<<endl;
}

void nextValue(int k) {
	int j;
	while(true) {
		x[k]=(x[k]+1)%(col+1);
		if(x[k]==0)
			return;
		for(j=1;j<=k-1;j++) {
			if(G[j][k]==1 && x[j]==x[k])
				break;
		}
		if(j==k)
			return;
	}
}
int c=0;
void mColoring(int k) {
	while(true) {
		nextValue(k);
		if(x[k]==0)
			return;
		if(k==n) {
			c++;
			displaySoln(x);
		}
		else 
			mColoring(k+1);
	}
}

int main() {
	readGraph();
	cout<<"Graph = "<<endl;
	displayGraph();
	cout<<"Enter the number of colors...";
	cin>>col;
    cout<<"Possible color combinations = "<<endl;
	mColoring(1);
    if(c==0)
        cout<<"No solutions exist"<<endl;
    else
	    cout<<"Number of solutions = "<<c<<endl;
	return 0;
}