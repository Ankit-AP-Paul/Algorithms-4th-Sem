#include<bits/stdc++.h>
using namespace std;

struct Jobs {
    string name;
    int deadline;
    int profit;
};

void sort(struct Jobs arr[], int n) {
    //bubble sort
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-1-i;j++) {
            if(arr[j].profit<arr[j+1].profit) {
                struct Jobs temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void JSD(struct Jobs arr[], int n, bool slots[], string x[]) {
    for(int i=0;i<n;i++) {
        slots[i]=false;
        x[i]="";
    }
    for(int i=0;i<n;i++) {
        for(int j=min(arr[i].deadline,n)-1;j>=0;j--) {
            if(slots[j]==false) {
                slots[j]=true;
                x[j]=arr[i].name;
                break;
            }
        }
    }
}

int main() {
    int n;
    cout<<"Enter the number of jobs = ";
    cin>>n;
    struct Jobs *arr = new struct Jobs[n];
    string *x = new string[n];
    bool *slots = new bool[n];
    for(int i=0;i<n;i++) {
        cout<<"Enter job name, deadline and profit = ";
        cin>>arr[i].name>>arr[i].deadline>>arr[i].profit;
    }
    sort(arr,n);
    JSD(arr,n,slots,x);
    cout<<"Jobs to be done in order = ";
    int i=0,profit=0;
    while(x[i]!="") {
        cout<<x[i]<<" ";
        profit+=arr[i].profit;
        i++;
    }
    cout<<endl;
    cout<<"Total profit = "<<profit<<endl;
    return 0;
}