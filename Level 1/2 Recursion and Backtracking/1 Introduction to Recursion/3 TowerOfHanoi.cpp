#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

void toh(int n, int t1id, int t2id, int t3id){
    if(!n) return;
    
    // write your code here
    toh(n-1, t1id, t3id, t2id); /* will print the instructions to
        move n-1 disks from t1 to t3 using t2 (*)
    */
   cout<<n<<"["<<t1id<<" -> "<<t2id<<"]\n";

   toh(n-1, t3id, t2id, t1id);
}

void solve(){
    optimize();
    int n;cin>>n;
    int n1,n2,n3;cin>>n1>>n2>>n3;
    toh(n, n1, n2, n3);
}

int main(){
    solve();

    return 0;
}