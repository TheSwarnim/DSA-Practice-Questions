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
    cin >> n;
    Vi arr(n);
    for (auto &&i : arr)
    {
        cin >> i;
    }
    
    int lis[n]; // it will store the count
    lis[0] = 1;

    for(int i = 1; i < n; i++){
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j] && count < lis[j]){
                count = lis[j];
            }
        }
        lis[i] = count + 1;    
    } 

    int lds[n];
    lds[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        int count = 0;
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j] && count < lds[j]){
                count = lds[j];
            }
        }
        lds[i] = count + 1;
    }
    
    int maxBitonic = 0;

    for (int i = 0; i < n; i++)
    {
        maxBitonic = max(maxBitonic, lis[i] + lds[i]);
    }
    
    cout << maxBitonic - 1 << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}