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

void countABCsubsequencesofficial(string s){
    int n = s.size();

    int a = 0, ab = 0, abc = 0;

    for (int i = 0; i < n; i++)
    {
        char ch = s.at(i);
        if(ch=='a'){
            a = 2*a + 1;
        }else if(ch=='b'){
            ab = 2*ab + a;
        }else{
            abc = 2*abc + ab;
        }
    }
    
    cout << abc << "\n";
}

void solve(){
    optimize();
    
    string s; cin>>s;
    
    countABCsubsequencesofficial(s);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}