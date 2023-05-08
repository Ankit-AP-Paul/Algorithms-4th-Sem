#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
    int vertex1, vertex2, weight;
};

class Graph {
public:
    int vertices, edges;
    Edge *edge_list;
    Edge *MST;
    Graph(int v, int e) {
        vertices=v;
        edges=e;
        edge_list=new Edge[e];
        MST=new Edge[v-1];
    }
    void addEdges(int v1, int v2, int w, int i) {
            edge_list[i].vertex1=v1;
            edge_list[i].vertex2=v2;
            edge_list[i].weight=w;
    }
    void sort() {
        for(int i=0;i<edges-1;i++) {
            for(int j=0;j<edges-1-i;j++) {
                if(edge_list[j].weight>edge_list[j+1].weight) {
                    Edge temp=edge_list[j];
                    edge_list[j]=edge_list[j+1];
                    edge_list[j+1]=temp;
                }
            }
        }
    }
    void display() {
        for(int i=0;i<edges;i++) {
            printf("Edge[%c, %c] --> %d\n", edge_list[i].vertex1+'A', edge_list[i].vertex2+'A', edge_list[i].weight);
        }
    }
};

int find(int parent[], int index) {
    while(parent[index]>0) {
        index=parent[index];
    }
    return index;
}

void simpleUnion(int parent[], int i, int j) {
    int u=find(parent, i);
    int v=find(parent, j);
    parent[u]=v;
}

void kruskal(Graph g) {
    g.sort();
    int *parent=new int[g.vertices];
    int edge=0;
    Edge *mst=new Edge[g.vertices-1];
    for(int i=0;i<g.vertices;i++) {
        parent[i]=-1;
    }
    for(int i=0;i<g.edges;i++) {
        if(find(parent, g.edge_list[i].vertex1)!=find(parent,g.edge_list[i].vertex2)) {
            mst[edge].vertex1=g.edge_list[i].vertex1;
            mst[edge].vertex2=g.edge_list[i].vertex2;
            mst[edge].weight=g.edge_list[i].weight;
            edge++;
            simpleUnion(parent,g.edge_list[i].vertex1,g.edge_list[i].vertex2);
        }
    }
    for(int i=0;i<g.vertices-1;i++) {
         printf("Edge[%c, %c] --> %d\n", mst[i].vertex1+'A', mst[i].vertex2+'A', mst[i].weight);
    }
}

int main() {
    int v, e=0, t=0;
    FILE *fp;
    fp=fopen("graph.txt","r");
    if(fp==NULL) {
        cout<<"Error to open file"<<endl;
        return 0;
    }
    fscanf(fp, "%d", &v);
    int **adjM=new int*[v];
    for(int i=0;i<v;i++) {
        adjM[i]=new int[v];
        for(int j=0;j<v;j++) {
            fscanf(fp, "%d", &adjM[i][j]);
            if(adjM[i][j]!=0)
                e++;
        }

    }
    e=e/2;
    Graph g(v,e);
    for(int i=0;i<v;i++) {
        for(int j=0;j<i;j++) {
            if(adjM[i][j]!=0) {
                g.addEdges(i,j,adjM[i][j],t);
                t++;
            }

        }
    }
    cout<<"Input Graph = "<<endl;
    g.display();
    cout<<"MST = "<<endl;
    kruskal(g);
}