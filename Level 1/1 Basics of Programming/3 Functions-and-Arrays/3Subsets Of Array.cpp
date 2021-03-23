// recursive (iterative iska neecha)
#include<bits/stdc++.h>
using namespace std;

void printAllSubArrays(vector<int> &arr, int n, int tempArr[]){
    for (int i = 0; i < n; i++)
    {
        if(tempArr[i]==1) cout<<arr[i]<<"\t";
        else cout<<"-\t";
    }
    cout<<"\n";
}

void generateAllBinaryStrings(int n, int tempArr[], int i, vector<int> &arr) 
{ 
    if (i == n) { 
        printAllSubArrays(arr, n, tempArr); 
        return; 
    } 
    tempArr[i] = 0; 
    generateAllBinaryStrings(n, tempArr, i + 1, arr); 
  
    tempArr[i] = 1; 
    generateAllBinaryStrings(n, tempArr, i + 1, arr); 
} 

int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for (auto &&i : arr)
    {
        cin>>i;
    }
    
    int tempArr[n];
    generateAllBinaryStrings(n, tempArr, 0, arr);
    return 0;
}