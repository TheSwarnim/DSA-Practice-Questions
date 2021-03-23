#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define calcTime cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

void maxSumofNonAdjElements(vector<int> &arr){
    int n = arr.size();

    int exc = 0;
    int inc = arr[0];

    for (int i = 1; i < n; i++)
    {
        int newInc = exc + arr[i];
        int newExc = max(inc, exc);

        inc = newInc;
        exc = newExc;
    }
    
    cout << max(inc, exc) << "\n";
}

void solve(){
    optimize();
    
    int n; cin>>n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    
    maxSumofNonAdjElements(arr);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}