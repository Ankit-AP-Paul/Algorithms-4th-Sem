#include<bits/stdc++.h>
using namespace std;

void display(int arr[], int n) {
    for(int i=1;i<=n;i++) {
        printf("%-3d",arr[i]);
    }
    cout<<endl;
}

bool placeQueen(int x[], int k, int i) {
    // check if queen can be placed at kth row and ith column
    for(int j=1;j<=k-1;j++) {
        if(x[j]==i || abs(j-k)==abs(x[j]-i))
            return false;
    }
    return true;
}

int c=0;
void nQueen(int x[], int k, int n) {
    // k = row no.
    // n = no. of queens
    for(int i=1;i<=n;i++) {
        if(placeQueen(x,k,i)) {
            x[k]=i;
            if(k==n) {
                c++;
                display(x,n);
            }
            else {
                nQueen(x,k+1,n);
            }
        }
    }
}

int main() {
    int n;
    cout<<"Enter the number of queen...";
    cin>>n;
    int *x=(int*)calloc(n+1,sizeof(int));
    nQueen(x,1,n);
    if(c==0) {
        cout<<"No Solution exists"<<endl;
    }
    else {
        cout<<"Number of solutions = "<<c<<endl;
    }
    return 0;
}