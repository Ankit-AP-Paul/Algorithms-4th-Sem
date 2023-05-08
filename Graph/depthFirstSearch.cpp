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

class Stack {
public:
	Node *top;
	Stack() {
		top=NULL;
	}
	int isEmpty() {
		if(top==NULL)
			return 1;
		return 0;
	}
	void push(int item) {
		Node *cur=new Node(item);
		if(top==NULL) {
			top=cur;
			return;
		}
		cur->next=top;
		top=cur;
		return;
	}
	int peek() {
		return (top->data);
	}
	void pop() {
		top=top->next;
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

	//DFS
	cout<<"DFS = ";
	int vertex=0;
	int *visited=(int*)calloc(v,sizeof(int));
	Stack S;
	visited[vertex]=1;
	S.push(vertex);
	while(!S.isEmpty()) {
		vertex=S.peek();
		printf("%-3c",vertex+'A');
		S.pop();
		for(int j=0;j<v;j++) {
			if(adjM[vertex][j]==1) {
				if(visited[j]==0) {
					visited[j]=1;
					S.push(j);
				}
            }
		}
	}
}
	
