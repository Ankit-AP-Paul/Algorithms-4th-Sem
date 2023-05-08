#include<bits/stdc++.h>
using namespace std;

void findMinMax(int arr[], int low, int high, int *min, int *max) {
    if(low==high) {
        *min=*max=arr[low];
    }
    else if(low==high-1) {
        if(arr[low]<arr[high]) {
            *min=arr[low];
            *max=arr[high];
        }
        else {
            *min=arr[high];
            *max=arr[low];
        }
    }
    else {
        int mid=(low+high)/2;
        int min1, max1;
        findMinMax(arr,low,mid,min,max);
        findMinMax(arr,mid+1,high,&min1,&max1);
        if(*max<max1) {
            *max=max1;
        }
        if(*min>min1) {
            *min=min1;
        }
    }
}

void display(int arr[], int size) {
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main() {
    int size,key,min,max;
    cout<<"Enter the size of array...";
    cin>>size;
    int *arr=new int[size];
    cout<<"Enter array elements..."; 
    for(int i=0;i<size;i++) {
        cin>>arr[i];
    }
    cout<<"Original Array = ";
    display(arr,size);
    findMinMax(arr,0,size-1,&min,&max);
    cout<<"Minimum = "<<min<<"\tMaximum = "<<max<<endl;
    return 0;
}