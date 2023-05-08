#include<bits/stdc++.h>
using namespace std;

int adjM[10][10];

class Node {
public:
	int data;
    int weight;
	Node *next;
	Node(int item, int wt) {
		data=item;
        weight=wt;
		next=NULL;
	}
};

class LL {
public:
	Node *head;
	LL() {
		head=NULL;
	}
	void insert(int item, int wt) {
		Node *cur=new Node(item, wt);
		if(head==NULL) {
			head=cur;
			return;
		}
		cur->next=head;
		head=cur;
		return;
	}
	void display() {
		Node *temp=head;
		while(temp!=NULL) {
			printf("%c(%d) -> ",temp->data+'A',temp->weight);
			temp=temp->next;
		}
        cout<<"NULL"<<endl;
	}
    // void display2() {
	// 	Node *temp=head;
	// 	while(temp!=NULL) {
	// 		printf("%-3c",temp->data+'A');
	// 		temp=temp->next;
	// 	}
    //     cout<<endl;
	// }
};


class Edge {
public:
    int vertex1, vertex2, weight;
};

class Graph {
public:
    int vertices, edges;
    Edge *edge_list;
    LL *adjL;
    Graph(int v, int e) {
        vertices=v;
        edges=e;
        edge_list=new Edge[e];
        adjL=new LL[v];
    }
    void adjcencyList() {
        for(int i=0;i<vertices;i++) {
		    for(int j=0;j<vertices;j++) {
			    if(adjM[i][j]!=0) {
				    adjL[i].insert(j,adjM[i][j]);
			    }   
		}
	    }
    }
    void addEdges(int v1, int v2, int w, int i) {
            edge_list[i].vertex1=v1;
            edge_list[i].vertex2=v2;
            edge_list[i].weight=w;
    }
    // void sort() {
    //     for(int i=0;i<edges-1;i++) {
    //         for(int j=0;j<edges-1-i;j++) {
    //             if(edge_list[j].weight>edge_list[j+1].weight) {
    //                 Edge temp=edge_list[j];
    //                 edge_list[j]=edge_list[j+1];
    //                 edge_list[j+1]=temp;
    //             }
    //         }
    //     }
    // }
    void displayEdges() {
        for(int i=0;i<edges;i++) {
            printf("Edge[%c, %c] --> %d\n", edge_list[i].vertex1+'A', edge_list[i].vertex2+'A', edge_list[i].weight);
        }
    }
    void displayAdjList() {
        for(int i=0;i<vertices;i++) {
            printf("%c:  ",i+'A');
            adjL[i].display();
        }
    }
};

int minKey(Graph g,int key[], bool visited[]) {
    int min=9999;
    int minId=-1;
    for(int i=0;i<g.vertices;i++) {
        // cout<<"v="<<g.vertices<<endl;
        if(visited[i]==false) {
            if(min>key[i]) {
                min=key[i];
                minId=i;
            }
        }
    }
    // cout<<min<<minID<<endl;
    return minId;

}

void prims(Graph g, int r) {
    int *key=new int[g.vertices];
    int *parent=new int[g.vertices];
    bool *visited=new bool[g.vertices];
    for(int i=0;i<g.vertices;i++) {
        key[i]=9999;
        parent[i]=-1;
        visited[i]=false;
    }
    key[r]=0;
    // for(int i=0;i<g.vertices;i++) {
    //     cout<<key[i]<<endl;
    // }
    for(int i=0;i<g.vertices;i++) {
        int u=minKey(g,key,visited);
        // cout<<u<<endl;
        visited[u]=true;
        //------------using adjacency matrix-----------------------//
        // for(int v=0;v<g.vertices;v++) {
        //     if(adjM[u][v]!=0) {
        //         if(visited[v]==false && key[v]>adjM[u][v]) {
        //             key[v]=adjM[u][v];
        //             parent[v]=u;
        //         }
        //     }
        // }
        //------------using adjacency List-----------------------//
        Node *temp=g.adjL[u].head;
        while(temp!=NULL) {
                if(visited[temp->data]==false && key[temp->data]>temp->weight) {
                    key[temp->data]=temp->weight;
                    parent[temp->data]=u;
                }
            temp=temp->next;
        }

    }
    // cout<<"check"<<endl;
    int minWt=0;
    for(int i=0;i<g.vertices;i++) {
        // cout<<parent[i]<<endl;
        if(parent[i]!=-1) {
            printf("Edge[%c, %c] ---> %d\n",parent[i]+'A', i+'A', adjM[parent[i]][i]);
            minWt+=adjM[parent[i]][i];
        }
    }
    cout<<"Minimum Cost = "<<minWt<<endl;
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
    for(int i=0;i<v;i++) {
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
    cout<<"Original Graph = "<<endl;
    g.displayEdges();
    g.adjcencyList();
    cout<<"Adjacency List = "<<endl;
    g.displayAdjList();
    cout<<"Minimum Spanning tree = "<<endl;
    prims(g,0);
}