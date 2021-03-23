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

void buyAndSellStocks(Vi &arr, int n, int fee){
    int obsp = -arr[0]; //old buy state profit
    int ossp = 0; //old buy state profit
    
    for(int i=1; i<n; i++){
        int nbsp = 0;
        int nssp = 0;

        if(ossp - arr[i] > obsp){
            nbsp = ossp-arr[i];
        }else{
            nbsp = obsp;
        }

        if(obsp+arr[i] - fee > ossp){
            nssp = obsp+arr[i]-fee;
        }else{
            nssp = ossp;
        }

        obsp = nbsp;
        ossp = nssp;
    }

    cout << ossp << endl;
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

    int fee;
    cin>>fee;

    buyAndSellStocks(arr, n, fee);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}