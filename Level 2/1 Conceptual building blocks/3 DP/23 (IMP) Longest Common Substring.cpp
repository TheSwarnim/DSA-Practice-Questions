#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

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

void displayArray(string arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] << " ";
    }
    
    cout<<"\n";
}

void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    string s1prefix[s1.length()];
    string s2prefix[s2.length()];

    s1prefix[0] = s1[0];
    for(int i = 1; i < s1.length(); i++){
        s1prefix[i] = s1prefix[i - 1] + s1[i];
    }

    s2prefix[0] = s2[0];
    for(int i = 1; i < s2.length(); i++){
        s2prefix[i] = s2prefix[i - 1] + s2[i];
    }

    // displayArray(s1prefix, s1.length());
    // displayArray(s2prefix, s2.length());

    int maxVal = -1;
    vvi dp(s1.length(), vi(s2.length()));
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 0; j < s2.length(); j++)
        {
            if(s1prefix[i].at(s1prefix[i].length() - 1) == s2prefix[j].at(s2prefix[j].length() - 1)){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                maxVal = max(maxVal, dp[i][j]);
            }
        }
    }
    
    // displayMatrix(dp);
    cout << (maxVal == -1 ? 0 : maxVal) << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}