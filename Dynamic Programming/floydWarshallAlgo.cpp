#include<bits/stdc++.h>
using namespace std;
int w[20][20];
int dist[20][20];
int predecessor[20][20];

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

void floydWarshall(Graph g) {
    for(int i=0;i<g.vertices;i++) {
        for(int j=0;j<g.vertices;j++) {
            dist[i][j]=w[i][j];
            if(w[i][j]==0||w[i][j]==9999) {
                predecessor[i][j]=-1;
            }
            else {
                predecessor[i][j]=i;
            }
        }
    }
    for(int k=0;k<g.vertices;k++) {
        for(int i=0;i<g.vertices;i++) {
            for(int j=0;j<g.vertices;j++) {
                if(dist[i][k]!=9999 && dist[k][j]!=9999) {
                    if(dist[i][k]+dist[k][j]<dist[i][j]) {
                        dist[i][j]=dist[i][k]+dist[k][j];
                        predecessor[i][j]=predecessor[k][j];
                    }
                }
            }
        }
    }
    // cout<<"Distance[][] = "<<endl;
    // for(int i=0;i<g.vertices;i++) {
    //     for(int j=0;j<g.vertices;j++) {
    //         printf("%-3d",dist[i][j]);
    //     }
    //     cout<<endl;
    // }
    // cout<<"Predecessor[][] = "<<endl;
    // for(int i=0;i<g.vertices;i++) {
    //     for(int j=0;j<g.vertices;j++) {
    //         if(predecessor[i][j]!=-1)
    //             printf("%-3c",predecessor[i][j]+'A');
    //         else
    //             printf("-  ");
    //     }
    //     cout<<endl;
    // }
}

void printPath(int i, int j) {
    if(i==j)
        printf("%-3c",i+'A');
    else if(predecessor[i][j]==-1)
        cout<<"No Path"<<endl;
    else {
        printPath(i,predecessor[i][j]);
        printf("%-3c",j+'A');
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
    cout<<"All Edges = "<<endl;
    g.displayEdges();
    floydWarshall(g);
    cout<<"\nAll Pairs of Shortest Path = "<<endl;
    for(int i=0;i<g.vertices;i++) {
        for(int j=0;j<g.vertices;j++) {
            printf("Path from %c to %c (Cost = %d) -> ",i+'A',j+'A',dist[i][j]);
            printPath(i,j);
            cout<<endl;
        }
    }
    return 0;
}