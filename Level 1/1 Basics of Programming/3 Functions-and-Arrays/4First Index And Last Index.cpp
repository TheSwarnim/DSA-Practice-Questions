#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int data;
    cin>>data;
    
    // write your code here
    int lo = 0;
    int hi = n - 1;
    int fi = -1; //first index

    while(lo<=hi){
        int m = (lo+hi)/2;
        if(data>arr[m]){
            lo = m+1;
        }
        else if(data<arr[m]){
            hi = m-1;
        }
        else{
            fi=m;
            hi=m-1;
        }
    }

    cout<<fi<<endl;

    lo = 0;
    hi = n -1;
    int li = -1; //last index

    while(lo<=hi){
        int m = (lo+hi)/2;
        if(data>arr[m]){
            lo = m+1;
        }
        else if(data<arr[m]){
            hi = m-1;
        }
        else{
            li=m;
            lo=m+1;
        }
    }

    cout<<li<<endl;
    
    delete arr;
    return 0;
}
