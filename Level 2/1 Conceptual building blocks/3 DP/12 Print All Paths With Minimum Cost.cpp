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
    int n, m;
    cin >> n >> m;

    vector<Vi> arr(n, Vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }        
    }
    
    vector<Vi> dp(n, Vi(m));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if(i == n - 1 && j == m - 1){
                dp[i][j] = arr[i][j];
            } else if(i == n - 1) {
                dp[i][j] = dp[i][j + 1] + arr[i][j];
            } else if(j == m - 1) {
                dp[i][j] = dp[i + 1][j] + arr[i][j];
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + arr[i][j];
            }
        }
    }
    
    // displayMatrix(dp);
    cout << dp[0][0] << endl;
    
    queue<Pair> queue;
    queue.push(Pair("", 0, 0));

    while (!queue.empty()){
        Pair rem = queue.front();
        queue.pop();


        int i = rem.i;
        int j = rem.j;
        string psf = rem.psf;

        // base case
        if(rem.i == n - 1 && rem.j == m - 1){
            cout << rem.psf << endl;
        } else if(rem.i == n - 1){
            queue.push(Pair(psf + "H", i, j + 1));
        } else if(rem.j == m - 1){
            queue.push(Pair(psf + "V", i + 1, j));
        } else {
            if(arr[i + 1][j] < arr[i][j + 1]){
                queue.push(Pair(psf + "V", i + 1, j));
            } else if(arr[i + 1][j] > arr[i][j + 1]){
                queue.push(Pair(psf + "H", i, j + 1));
            } else {
                queue.push(Pair(psf + "V", i + 1, j));
                queue.push(Pair(psf + "H", i, j + 1));
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