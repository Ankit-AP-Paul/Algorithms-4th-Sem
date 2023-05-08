#include<bits/stdc++.h>
using namespace std;

int p[]={2,3,5,2,4};
int M[20][20]={0};
int S[20][20]={0};
int n;

void matrixChainOrder() {
	n=sizeof(p)/sizeof(p[0])-1;
	for(int i=1;i<=n;i++)
		M[i][i]=0;
	for(int len=2;len<=n;len++) {
		for(int i=1;i<=n-len+1;i++) {
			int j=i+len-1;
			M[i][j]=99999;
			for(int k=i;k<=j-1;k++) {
				int cost=M[i][k]+M[k+1][j]+(p[i-1]*p[k]*p[j]);
				if (cost<M[i][j]) {
					M[i][j]=cost;
					S[i][j]=k;
				}
			}
		}
	}
	cout<<"M Array = "<<endl;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			printf("%3d",M[i][j]);
		}	
		printf("\n");
	}
	cout<<"S Array = "<<endl;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			printf("%3d",S[i][j]);
		}	
		printf("\n");
	}
	
}

void printOptimalParenthesis(int i, int j) {
	if(i==j)
		printf("%c",i+'A');
	else {
		printf("(");
		printOptimalParenthesis(i, S[i][j]);
		printOptimalParenthesis(S[i][j]+1,j);
		printf(")");  
	}
}

int main() {
	matrixChainOrder();
	printOptimalParenthesis(0, n);
}

