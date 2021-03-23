#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

vector<string> gss(string s){
    // write your code here
    if(s.size() == 0) return {""};
    
    char ch = s.at(0);
    string ros = s.substr(1);

    vector<string> rres = gss(ros);
    vector<string> mres;
    
    for (auto &&rstr : rres)
    {
        mres.push_back(""+rstr);
    }
    
    for (auto &&rstr : rres)
    {
        mres.push_back(ch+rstr);
    }

    return mres;
}

void solve(){
    optimize();
    
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}

int main(){
    solve();

    return 0;
}