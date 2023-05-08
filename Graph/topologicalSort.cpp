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
    //Graph must be a DAG
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

    //topological Sort
    int *count=(int*)calloc(v,sizeof(int));
    for(int j=0;j<v;j++) {      //indegree calculation
        for(int i=0;i<v;i++) {
            count[j]+=adjM[i][j];
        }
    }
    // for(int i=0;i<v;i++) {
    //     printf("%3d",count[i]);
    // }
	Queue Q;
    for(int i=0;i<v;i++) {
        if(count[i]==0) {
            Q.insert(i);
        }
    }
    cout<<"Topological Sort = ";
    while(!Q.isEmpty()) {
        int u=Q.peek();
        Q.del();
        printf("%-3c",u+'A');
        for(int i=0;i<v;i++) {
            if(adjM[u][i]==1) {
                count[i]--;
                if(count[i]==0) {
                    Q.insert(i);
                }
            }
        }
    }
}
	
