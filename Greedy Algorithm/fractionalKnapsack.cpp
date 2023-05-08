#include<bits/stdc++.h>
using namespace std;

class Item {
public:
    int w, p;
};

void arrange(Item arr[], int n) {
    //bubble sort
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-1-i;j++) {
            double r1=(double)arr[j].p/(double)arr[j].w;
            double r2=(double)arr[j+1].p/(double)arr[j+1].w;
            if(r1<r2) {
                Item temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void fractionalKnapsack(Item arr[], int W, int n, double x[]) {
	for(int i=0;i<n;i++) {
	    x[i]=0.0;
	}
	int u=W;
	for(int i=0;i<n;i++) {
	    if(arr[i].w>u) {
	        x[i]=(double)u/(double)arr[i].w;
	        return;
	    }
	    x[i]=1.0;
	    u=u-arr[i].w;
	}
}

int main() {
    int n,W,profit=0;
    cout<<"Enter the number of items...";
    cin>>n;
    Item *arr=new Item[n];
    double *x=new double[n];
    for(int i=0;i<n;i++) {
        cout<<"Enter profit and weight...";
        cin>>arr[i].p;
        cin>>arr[i].w;
    }
    cout<<"Enter the maximum weight...";
    cin>>W;
    arrange(arr,n);
    fractionalKnapsack(arr,W,n,x);
    for(int i=0;i<n;i++) {
        profit+=arr[i].p*x[i];
    }
    cout<<"Maximum profit = "<<profit<<endl;
    return 0;
}