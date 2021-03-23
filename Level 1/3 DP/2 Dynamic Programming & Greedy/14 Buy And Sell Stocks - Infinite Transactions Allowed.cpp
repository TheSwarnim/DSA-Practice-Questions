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

void buyAndSellStocks(Vi &arr, int n){
    int bd = 0;
    int sd = 0;
    int profit = 0;

    for(int i=1; i<n; i++){
        if(arr[i] >= arr[i-1]){
            sd++;
        }else{
            profit += arr[sd] - arr[bd];
            bd = sd = i;
        }
    }

    profit += arr[sd] - arr[bd];

    cout<<profit<<endl;
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

    buyAndSellStocks(arr, n);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}