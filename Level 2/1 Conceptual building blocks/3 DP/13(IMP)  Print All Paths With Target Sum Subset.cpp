#include<bits/stdc++.h>
using namespace std;
#define Vi vector<int>

bool debug;
void optimize(){
    if(debug){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        #endif
    }
}

void calcTime(){
    if(debug){
        cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    }
}

void displayMatrix(vector<vector<int>> &arr){
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

class Pair{
    public:
        string psf;
        int i; // row
        int j; // column

        Pair(string psf, int i, int j): psf(psf), i(i), j(j){}
};

void solve(){
    int n;
    cin >> n;
    Vi arr(n);
    for (auto &&i : arr)
    {
        cin>>i;
    }    
    int tar;
    cin>>tar;

    vector<Vi> dp(n + 1, Vi(tar + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < tar + 1; j++)
        {
            if(j == 0){
                dp[i][j] = 1;
            } else if(i == 0){
                dp[i][j] = 0;
            } else {
                if(dp[i- 1][j] == 1){
                    dp[i][j] = 1;
                } else if(arr[i - 1] <= j && dp[i - 1][j - arr[i - 1]] == 1){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    
    cout << boolalpha << (dp[n][tar] == 1) << endl;
    
    queue<Pair> queue;
    queue.push(Pair("", n, tar));

    while (!queue.empty()){
        Pair rem = queue.front();
        queue.pop();
        
        int i = rem.i;
        int j = rem.j;
        string psf = rem.psf;

        if(i == 0 || j == 0){
            cout << psf << endl;
        } else {
            if(j >= arr[i - 1]){
                bool inc = dp[i - 1][j - arr[i - 1]] == 1; //include
                if(inc) {
                    queue.push(Pair(to_string(i - 1) + " " + psf, i - 1, j - arr[i - 1]));
                }
            }
            
            bool exc = dp[i - 1][j] == 1; //exclude
            if(exc) {
                queue.push(Pair(psf, i - 1, j));
            }
        }
    }
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}