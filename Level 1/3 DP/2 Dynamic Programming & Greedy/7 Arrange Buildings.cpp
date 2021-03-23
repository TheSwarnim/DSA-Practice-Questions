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

void arrangeBuildings(int n){
    long long occOfZeros = 1;
    long long occOfOnes = 1;

    for(long long i=2; i<=n; i++){
        long long newCntZeros = occOfOnes;
        long long newCntOnes = occOfZeros + occOfOnes;

        occOfZeros = newCntZeros;
        occOfOnes = newCntOnes;
    }
    
    long long ans = (occOfOnes+occOfZeros)*(occOfOnes+occOfZeros);
    cout<<ans<<"\n";
}

void solve(){
    optimize();
    
    int n; cin>>n;
    
    arrangeBuildings(n);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}