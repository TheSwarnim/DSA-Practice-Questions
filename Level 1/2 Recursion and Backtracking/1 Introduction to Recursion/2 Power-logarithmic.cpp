#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int powerLogarithmic(int x,int n){
    // write your code here
    if(n==0){
        return 1;
    }
    
    int xpnb2 = powerLogarithmic(x, n/2);
    int xn = xpnb2*xpnb2;

    if(n%2==0) return xn;
    else return xn*x;
}

void solve(){
    optimize();
    int n,x; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}

int main(){
    solve();

    return 0;
}