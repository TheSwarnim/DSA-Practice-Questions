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
    Vi values(n);
    for (auto &&i : values)
    {
        cin>>i;
    }
    
    Vi weights(n);
    for (auto &&i : weights)
    {
        cin>>i;
    }
    
    int cap;
    cin >>cap;

    vector<Vi> dp(n + 1, Vi(cap + 1));

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
        {
            if(i ==0 || j==0){
                dp[i][j] = 0;
            } else {
                int wt = weights[i - 1];
                int val = values[i - 1];
                if(j >= wt){
                    dp[i][j] = max(dp[i - 1][j], val + dp[i - 1][j - wt]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }        
    }
    
    // displayMatrix(dp);
    cout << dp[n][cap] << endl;

    queue<Pair> queue;
    queue.push(Pair("", n, cap));

    while (!queue.empty()){
        Pair rem = queue.front();
        queue.pop();

        int i = rem.i;
        int j = rem.j;
        string psf = rem.psf;
        
        if(i == 0 || j == 0){
            cout << psf << endl;
        } else {
            // include
            int inc = dp[i - 1][j - weights[i - 1]] + values[i - 1];
            if(dp[i][j] == inc){
                queue.push(Pair(to_string(i - 1) + " " + psf, i - 1, j - weights[i - 1]));
            }

            // exclude
            int exc = dp[i - 1][j];
            if(dp[i][j] == exc){
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