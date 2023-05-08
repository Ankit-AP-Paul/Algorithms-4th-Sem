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

class LL {
public:
	Node *head;
	LL() {
		head=NULL;
	}
	void insert(int item) {
		Node *cur=new Node(item);
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
			printf("%c -> ",temp->data+'A');
			temp=temp->next;
		}
        cout<<"NULL"<<endl;
	}
    void display2() {
		Node *temp=head;
		while(temp!=NULL) {
			printf("%-3c",temp->data+'A');
			temp=temp->next;
		}
        cout<<endl;
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
	int totDegree=0;
	LL *adjL=new LL[v];
	for(int i=0;i<v;i++) {
		for(int j=0;j<v;j++) {
			if(adjM[i][j]==1) {
				totDegree++;
				adjL[i].insert(j);
			}
		}
	}
	cout<<"Adjacency List = "<<endl;
	for(int i=0;i<v;i++) {
		printf("%c: ",i+'A');
		adjL[i].display();
	}
    cout<<endl;
	cout<<"Total degree of graph = "<<totDegree<<endl;
    cout<<endl;
	cout<<"Number of edges = "<<(totDegree/2)<<endl;
    cout<<endl;
	char ch;
	cout<<"Enter the vertex...";
    cin>>ch;
	int n=ch-'A';
    cout<<"Adjacent vertices of "<<ch<<" = ";
    adjL[n].display2();
	return 0;
}
