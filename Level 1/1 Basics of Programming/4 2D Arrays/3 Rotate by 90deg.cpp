#include<bits/stdc++.h>
using namespace std;

void displayMatrix(vector<vector<int>> &arr){
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void swapMatrix(vector<vector<int>> &arr){ //swapping the upper half of matrix
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr[0].size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void solve() {
    int n, m;
    cin>>n;
    m=n;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }

    reverse(begin(a), end(a));

    swapMatrix(a);

    displayMatrix(a);
}

int main(){
    solve();

    return 0;
}
