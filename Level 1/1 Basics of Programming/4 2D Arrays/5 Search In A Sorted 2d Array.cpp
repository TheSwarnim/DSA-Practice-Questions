#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

void displayMatrix(vector<vector<long long>> &arr){
    for (long long i = 0; i < arr.size(); i++)
    {
        for (long long j = 0; j < arr[0].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void findXinMatrix(vector<vector<long long>> &arr, long long x){
    long long n=arr.size();

    int i=0;
    int j=n-1;

    while(i<n && j>=0){
        if(x==arr[i][j]){
            cout<<i<<"\n";
            cout<<j<<"\n";
            return;
        }else if(x < arr[i][j]) j--;
        else i++;
    }
    cout<<"Not Found\n";
}

void solve(){
    optimize();
    long long n,m;
    cin>>n;
    m=n;

    vector<vector<long long>> arr(n, vector<long long>(m));

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    long long x; cin>>x;
    findXinMatrix(arr, x);
}

int main(){
    solve();

    return 0;
}