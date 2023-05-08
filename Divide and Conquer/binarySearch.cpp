#include<bits/stdc++.h>
using namespace std;

int binaryS(int arr[], int low, int high, int key) {
    //arr[] needs to be sorted in ascending order
    if (low<=high) {
        int mid=(low+high)/2;
        if(arr[mid]==key) {
            return mid;
        }
        else if(key<arr[mid]) {
            return(binaryS(arr,low,mid-1,key));
        }
        else {
            return(binaryS(arr,mid+1,high,key));
        }
    }
    return -1;
}

void display(int arr[], int size) {
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main() {
    int size,key;
    cout<<"Enter the size of array...";
    cin>>size;
    int *arr=new int[size];
    cout<<"Enter array elements...";
    for(int i=0;i<size;i++) {
        cin>>arr[i];
    }
    cout<<"Original Array = ";
    display(arr,size);
    cout<<"Enter the key to be searched...";
    cin>>key;
    int pos=binaryS(arr,0,size-1,key);
    if(pos!=-1) {
        cout<<"Item found at position "<<pos+1<<endl;
    }
    else {
        cout<<"Item not found"<<endl;
    }
    return 0;
}