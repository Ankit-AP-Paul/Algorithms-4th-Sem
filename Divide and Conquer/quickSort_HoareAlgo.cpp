#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

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

void quickSort(int arr[], int low, int high) {
    if(low<high) {
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
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
    quickSort(arr,0,size-1);
    cout<<"Sorted Array = ";
    display(arr,0,size-1);
    return 0;
}