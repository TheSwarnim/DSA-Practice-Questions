#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

void printSS(string ques, string ans){
    // write your code here

    // base case
    if(ques.size()==0){
        cout<<ans<<endl;
        return;
    }

    char ch = ques.at(0);

    // ch says "YES"
    printSS(ques.substr(1), ans+ch);
    
    // ch says "NO"
    printSS(ques.substr(1), ans);
}

void solve(){
    optimize();
    
    string str;
    cin >> str;
    printSS(str, "");
}

int main(){
    solve();

    return 0;
}