#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

void printPermutations(string str, string asf){
    // write your code here
    // handle base case
    if(str.length()==0){
        cout<<asf<<endl;
        return;
    }
    
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str.at(i);
        printPermutations(str.substr(0, i)+str.substr(i+1), asf+ch);
    }
    
}

void solve(){
    optimize();
    
    string str;
    cin>>str;
    printPermutations(str,"");
}

int main(){
    solve();

    return 0;
}