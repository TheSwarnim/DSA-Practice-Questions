#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

void printIncDec(int n){
    // write your code here
    if(n==0){
        return;
    }

    cout<<n<<endl; 
    
    printIncDec(n-1);

    cout<<n<<endl;
}


void solve(){
    optimize();
    int n;
    cin>>n;
    printIncDec(n);
}

int main(){
    solve();

    return 0;
}