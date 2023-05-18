#include<bits/stdc++.h>
using namespace std;

int n;
int G[10][10]={0};
int x[10]={0};

void readGraph() {
    FILE *fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL) {
        cout<<"Error in openning file!"<<endl;
        return;
    }
    fscanf(fp,"%d",&n);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            fscanf(fp,"%d",&G[i][j]);
        }
    }
}

void displayGraph() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%-3d",G[i][j]);
        }
        cout<<endl;
    }
}

void displaySoln() {
    for(int i=1;i<=n;i++) {
        printf("%-3c",x[i]-1+'A');
    }
    cout<<endl;
}

void nextValue(int k) {
    int j;
    do{
        x[k]=(x[k]+1)%(n+1);
        if(x[k]==0)
            return;
        if(k > 1 && G[x[k-1]][x[k]] == 0)
            continue;
        for(j=k-1;j>=1;j--) {
            if(x[j]==x[k])
                break;
        }
        if(j==0) {
            if(k < n || (k == n && G[x[n]][x[1]] == 1))
                return;
        }
    }
    while(true);
}

int c=0;
void hamiltonian(int k) {
    do {
        nextValue(k);
        if(x[k]==0)
            return;
        if(k==n) {
            c++;
            displaySoln();
        }
        else {
            hamiltonian(k+1);
        }
    }
    while (true);
}

int main() {
    readGraph();
    displayGraph();
    cout<<"Hamiltonian cycles are = "<<endl;
    hamiltonian(1);
    if(c==0) {
        cout<<"No hamiltonian cycle exists"<<endl;
    }
    return 0;
}