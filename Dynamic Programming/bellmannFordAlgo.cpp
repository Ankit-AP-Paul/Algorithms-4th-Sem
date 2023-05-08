#include<bits/stdc++.h>
using namespace std;
int w[20][20];

class Edge {
public:
    int vertex1, vertex2, weight;
};

class Graph {
public:
    int vertices, edges;
    Edge *edgeL;
    Graph(int v, int e) {
        vertices=v;
        edges=e;
        edgeL=new Edge[edges];
    }
    void addEdges(int v1, int v2, int wt, int i) {
        edgeL[i].vertex1=v1;
        edgeL[i].vertex2=v2;
        edgeL[i].weight=wt;
    }
    void displayEdges() {
        for(int i=0;i<edges;i++) {
            printf("Edges[%c, %c] -> %d\n",edgeL[i].vertex1+'A', edgeL[i].vertex2+'A', edgeL[i].weight);
        }
    }
};

void bellmanFord(Graph g, int dist[], int prdecessor[], int s) {
    for(int i=0;i<g.vertices;i++) {
        dist[i]=9999;
        prdecessor[i]=-1;
    }
    dist[s]=0;
    for(int i=0;i<g.vertices-1;i++) {
        for(int j=0;j<g.edges;j++) {
            int u=g.edgeL[j].vertex1;
            int v=g.edgeL[j].vertex2;
            if(dist[u]+w[u][v]<dist[v]) {
                dist[v]=dist[u]+w[u][v];
                prdecessor[v]=u;
            }
        }
    }
}

void displayPath(int predecessor[], int i) {
    if(i==-1)
        return;
    else {
        displayPath(predecessor,predecessor[i]);
        printf("%-3c", i+'A');
    }
}

int main() {
    int v,e=0,t=0;
    FILE *fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL) {
        cout<<"Error in openning file"<<endl;
        return 0;
    }
    fscanf(fp, "%d", &v);
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            fscanf(fp, "%d", &w[i][j]);
            if(w[i][j]!=0 && w[i][j]!=9999)
                e++;
        }
    }
    Graph g(v,e);
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            if(w[i][j]!=0 && w[i][j]!=9999) {
                g.addEdges(i,j,w[i][j],t);
                t++;
            }
        }
    }
    g.displayEdges();
    int *dist=new int[v];
    int *predecessor=new int[v];
    char s, d;
    cout<<"Enter the source and destination vertex = ";
    cin>>s>>d;
    int src=s-'A';
    int dest=d-'A';
    bellmanFord(g,dist,predecessor,src);
    displayPath(predecessor,dest);
    cout<<"\nCost = "<<dist[dest]<<endl;
    return 0;
}