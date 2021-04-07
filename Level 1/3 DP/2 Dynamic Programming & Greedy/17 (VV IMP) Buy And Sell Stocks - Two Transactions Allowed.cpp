#include<bits/stdc++.h>
using namespace std;
#define Vi vector<int>

bool debug;
void optimize(){
    if(debug){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        #endif
    }
}

void calcTime(){
    if(debug){
        cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    }
}

void solve(){
    int n;
    cin>>n;
    Vi arr(n);
    for (auto &&i : arr)
    {
        cin>>i;
    }
    
    int ssp[n];
    int minVal = arr[0];
    ssp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        minVal = min(minVal, arr[i]);
        
        if(minVal > arr[i]){
            minVal = arr[i];
        }
        int currSsp = arr[i] - minVal;
        
        ssp[i] = max(currSsp, ssp[i - 1]);
    }

    int bsp[n];
    bsp[n - 1] = 0;
    int maxVal = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        maxVal = max(maxVal, arr[i]);

        int currBsp = maxVal - arr[i];
        bsp[i] = max(currBsp, bsp[i + 1]);
    }
    
    int maxProfit = -1;

    for (int i = 0; i < n; i++)
    {
        maxProfit = max(maxProfit, ssp[i] + bsp[i]);
    }
    
    cout << maxProfit << endl;
}

int main(){
    debug = 0;
    optimize();
    
    solve();

    calcTime();
    return 0;
}