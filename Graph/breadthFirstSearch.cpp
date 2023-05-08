#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(int item) {
		data=item;
		next=NULL;
	}
};

class Queue {
public:
	Node *head;
	Queue() {
		head=NULL;
	}
	int isEmpty() {
		if(head==NULL)
			return 1;
		return 0;
	}
	void insert(int item) {
		Node *cur=new Node(item);
		if(head==NULL) {
			head=cur;
			return;
		}
		Node *temp=head;
        while(temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=cur;
		return;
	}
	int peek() {
		return (head->data);
	}
	void del() {
		head=head->next;
	}
};

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
	
	cout<<"Adjacency Matrix = "<<endl;
	printf("   ");
	for(int j=0;j<v;j++)
			printf("%-3c",j+'A');
	cout<<endl;
	for(int i=0;i<v;i++) {
		printf("%-3c",i+'A');
		for(int j=0;j<v;j++) {
			printf("%-3d",adjM[i][j]);
		}
		cout<<endl;
	}

	//BFS
	cout<<"BFS = ";
	int vertex=0;
	int *visited=(int*)calloc(v,sizeof(int));
	Queue Q;
	visited[vertex]=1;
	Q.insert(vertex);
	while(!Q.isEmpty()) {
		vertex=Q.peek();
		printf("%-3c",vertex+'A');
		Q.del();
		for(int j=0;j<v;j++) {
			if(adjM[vertex][j]==1) {
				if(visited[j]==0) {
					visited[j]=1;
					Q.insert(j);
				}
            }
		}
	}
}
	
