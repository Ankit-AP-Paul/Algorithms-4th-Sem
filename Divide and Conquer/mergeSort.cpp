 #include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int *M=new int[high-low+1];
    int index1=low, index2=mid+1;
    int t=0;
    while(index1<=mid && index2<=high) {
        if(arr[index1]<arr[index2]) {
            M[t++]=arr[index1++];
        }
        else {
            M[t++]=arr[index2++];
        }
    }
    while(index1<=mid) {
        M[t++]=arr[index1++];
    }
    while(index2<=high) {
        M[t++]=arr[index2++];
    }
    for(int i=low,j=0;i<=high;i++,j++) {
        arr[i]=M[j];
    }
}

void mergeSort(int arr[], int low, int high) {
    if(low<high) {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
    mergeSort(arr,0,size-1);
    cout<<"Sorted Array = ";
    display(arr,0,size-1);
    return 0;
}