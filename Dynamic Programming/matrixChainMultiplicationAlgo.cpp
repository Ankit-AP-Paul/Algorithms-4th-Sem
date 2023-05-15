#include<iostream>
#include<stdio.h>
using namespace std;

int M[10][10]={0};
int S[10][10]={0};

void matrixChainOrder(int p[], int n) {
    for(int i=1;i<=n;i++) {
        M[i][i]=0;
    }
    for(int len=2;len<=n;len++) {
        for(int i=1;i<=n-len+1;i++) {
            int j=i+len-1;
            M[i][j]=9999;
            for(int k=i;k<=j-1;k++) {
                int cost=M[i][k]+M[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(cost<M[i][j]) {
                    M[i][j]=cost;
                    S[i][j]=k;
                }
            }
        }
    }
    cout<<"M[] ->"<<endl;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%-3d",M[i][j]);
        }
        cout<<endl;
    }
    cout<<"S[] ->"<<endl;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%-3d",S[i][j]);
        }
        cout<<endl;
    }
}

void printOptimalParenthesis(int i, int j) {
    if(i==j) {
        printf("%c",i+'A');
    }
    else {
        printf("(");
        printOptimalParenthesis(i,S[i][j]);
        printOptimalParenthesis(S[i][j]+1,j);
        printf(")");
    }
}

int main() {
    int n;
    cout<<"Enter the size...";
    cin>>n;
    int *p=new int[n];
    cout<<"Enter the elements...";
    for(int i=0;i<n;i++) {
        cin>>p[i];
    }
    matrixChainOrder(p,n-1);
    cout<<"Matrix Order = ";
    printOptimalParenthesis(0,n-1);
    return 0;
}