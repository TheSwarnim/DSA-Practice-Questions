#include <bits/stdc++.h>

using namespace std;

int main(int argc, char**argv){
    int n;
    cin>>n;
    
    //write your code here
    vector<int> arr;
    arr.push_back(1);

    for(int i=1; i<=n; i++){
        for (auto &&x : arr)
        {
            cout<<x<<"\t";
        }

        vector<int> tempArr;
        tempArr.push_back(1);
        for(int i=1; i<arr.size(); i++){
            tempArr.push_back(arr[i-1] + arr[i]);
        }
        tempArr.push_back(1);
        
        arr = tempArr;
        
        cout<<"\n";
    }
}