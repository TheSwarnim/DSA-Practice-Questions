#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define calcTime cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
#define Vi vector<int>

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

void solve(){
    optimize();
    
    int n;
    cin>>n;

    Vi arr(n);
    for (auto &&i : arr)
    {
        cin>>i;
    }

    int obsp = -arr[0];
    int ossp = 0;
    int ocsp = 0;

    for (int i = 1; i < n; i++)
    {
        int nbsp = 0;
        int nssp = 0;
        int ncsp = 0;

        if(ocsp - arr[i] > obsp){
            nbsp = ocsp - arr[i];
        } else {
            nbsp = obsp;
        }

        if(obsp + arr[i] > ossp){
            nssp = obsp + arr[i];
        } else {
            nssp = ossp;
        }

        if(ossp > ocsp){
            ncsp = ossp;
        } else {
            ncsp = ocsp;
        }

        obsp = nbsp;
        ossp = nssp;
        ocsp = ncsp;
    }
    cout << ossp << endl;  
    
    calcTime;
}

int main(){
    solve();

    return 0;
}