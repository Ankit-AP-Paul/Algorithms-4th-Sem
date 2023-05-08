#include<bits/stdc++.h>
using namespace std;

class Items {
public:
    int profit;
    int weight;
};

int knapsack(Items arr[], int size, int maxCapacity) {
    int table[size+1][maxCapacity+1];
    for(int i=0;i<=maxCapacity;i++) {
        table[0][i]=0;
    }
    for(int i=0;i<=size;i++) {
        table[i][0]=0;
    }
    for(int i=1;i<=size;i++) {
        for(int j=1;j<=maxCapacity;j++) {
            if(arr[i].weight>j)
                table[i][j]=table[i-1][j];
            else
                table[i][j]=max(table[i-1][j],arr[i].profit+table[i-1][j-arr[i].weight]);
        }
    }
    // for(int i=0;i<=size;i++) {
    //     for(int j=0;j<=maxCapacity;j++) {
    //         printf("%-4d",table[i][j]);
    //     }
    //     cout<<endl;
    // }
    return table[size][maxCapacity];
}

int main() {
    int size, maxCapacity, maxProfit;
    cout<<"Enter the number of items...";
    cin>>size;
    Items *arr=new Items[size+1];
    for(int i=1;i<=size;i++) {
        printf("Enter profit and weight of item[%d]...",i);
        cin>>arr[i].profit>>arr[i].weight;
    }
    cout<<"Enter max capacity of the knapsack...";
    cin>>maxCapacity;
    cout<<"\nItems available = "<<endl;
    for(int i=1;i<=size;i++) {
        printf("Item[%d] ---> profit: %d   weight: %d\n",i,arr[i].profit, arr[i].weight);
    }
    cout<<endl;
    maxProfit=knapsack(arr,size,maxCapacity);
    cout<<"Maximum profit = "<<maxProfit<<endl;
}