#include<bits/stdc++.h>
using namespace std;

int ternaryS(int arr[], int low, int high, int key) {
    //arr[] needs to be sorted in ascending order
    if(low<=high) {
        int mid1=low+(high-low)/3;
        int mid2=high-(high-low)/3;
        if(arr[mid1]==key) {
            return mid1;
        }
        else if(arr[mid2]==key) {
            return mid2;
        }
        else if(arr[mid1]>key) {
            return(ternaryS(arr,low,mid1-1,key));
        }
        else if(arr[mid2]<key) {
            return(ternaryS(arr,mid2+1,high,key));
        }
        else {
            return(ternaryS(arr,mid1+1, mid2-1, key));
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
    int pos=ternaryS(arr,0,size-1,key);
    if(pos!=-1) {
        cout<<"Item found at position "<<pos+1<<endl;
    }
    else {
        cout<<"Item not found"<<endl;
    }
    return 0;
}