#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define calcTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

void printEncoding(string str, string asf){
    if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }
    
    if(str[0] == '0'){
        return;
    }

    string s1 = str.substr(0,1);
    string ros1 = str.substr(1);
    printEncoding(ros1,asf + (char)(stoi(s1) + 'a' - 1));

    if(str.length() >= 2){
        string s2 = str.substr(0,2);
        string ros2 = str.substr(2);
        if(stoi(s2) <= 26)
        printEncoding(ros2,asf + (char)(stoi(s2) + 'a' - 1));
    }

}

void solve(){
    optimize();
    
    string str;
    cin>>str;
    printEncoding(str,"");
    
    calcTime;
}

int main(){
    solve();

    return 0;
}
