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

    // set is the subset
    // sos is sum of subset
    // tar is target
void printTargetSumSubsets(vector<int> &arr, int idx, string set, int sos, int tar){
    // base cases
    if(sos>tar){
        return;
    }
    
    if(idx==arr.size()){
        if(sos==tar){
            cout<<set<<", .\n";
        }
        return;
    }

    int ttlVal = arr[idx]+sos;
    // current idx accept the proposal
    string tempSet = set;
    if(set.length()!=0) tempSet += ", ";
    printTargetSumSubsets(arr, idx+1, tempSet+to_string(arr[idx]), ttlVal, tar);

    // current idx reject the proposal
    printTargetSumSubsets(arr, idx+1, set, sos, tar);
}

void solve(){
    optimize();
    
    int n;
    cin>>n;

    vector<int> arr(n);
    for (auto &i : arr)
    {
        cin>>i;
    }

    int tar; cin>>tar;

    printTargetSumSubsets(arr, 0, "", 0, tar);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}