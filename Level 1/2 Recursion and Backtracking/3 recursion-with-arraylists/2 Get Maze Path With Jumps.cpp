#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr==dr && sc==dc){
        return {""};
    }

    vector<string> paths;
    // horizontal moves
    for(int ms = 1; ms <= dc - sc; ms++){ //ms: move sizes
        vector<string> hpaths = getMazePaths(sr, sc+ms, dr, dc);
        for (auto hpath : hpaths)
        {
            paths.push_back("h"+to_string(ms)+hpath);
        }
    }

    // vertical moves
    for(int ms = 1; ms <= dr - sr; ms++){ //ms: move sizes
        vector<string> vpaths = getMazePaths(sr+ms, sc, dr, dc);
        for (auto vpath : vpaths)
        {
            paths.push_back("v"+to_string(ms)+vpath);
        }
    }

    // diagonal moves
    for(int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++){ //ms: move sizes
        vector<string> dpaths = getMazePaths(sr+ms, sc+ms, dr, dc);
        for (auto dpath : dpaths)
        {
            paths.push_back("d"+to_string(ms)+dpath);
        }
    }
    
    return paths;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}

void solve(){
    optimize();
    
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);
}

int main(){
    solve();

    return 0;
}