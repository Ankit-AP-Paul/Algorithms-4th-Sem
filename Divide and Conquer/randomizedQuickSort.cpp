#include<bits/stdc++.h>
using namespace std;

int swap(int arr[], int i, int j) {
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

//using Hoare Algorithm
int partition(int arr[], int low, int high) {
    int pivot=arr[low];
    int i=low, j=high+1;
    while(i<=j) {
        do {
            i++;
        } while(i<=high && arr[i]<=pivot);
        do {
            j--;
        } while(arr[j]>pivot);
        if(i<j) {
            swap(arr,i,j);
        }
    }
    swap(arr,j,low);
    return j;
}

void RQSort(int arr[], int low, int high) {
    if(low<high) {
        if(high-low+1>5) {
            int pos=low+rand()%(high-low+1);
            swap(arr,pos,low);
        }
        int pivot=partition(arr,low,high);
        RQSort(arr,low,pivot-1);
        RQSort(arr,pivot+1,high);
    }
}


void display(int arr[], int low, int high) {
    for(int i=low;i<=high;i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main() {
    int size;
    cout<<"Enter the size of array...";
    cin>>size;
    int *arr=new int[size];
    cout<<"Enter array elements...";
    for(int i=0;i<size;i++) {
        cin>>arr[i];
    }
    cout<<"Original Array = ";
    display(arr,0,size-1);
    RQSort(arr,0,size-1);
    cout<<"Sorted Array = ";
    display(arr,0,size-1);
    return 0;
}