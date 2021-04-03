#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define calcTime cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
#define Vi vector<int>

void optimize(){
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
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

bool possible(vector<Vi> &arr, int x, int y){
    int n = arr.size();
    // for column
    for (int j = 0; j < y; j++)
    {
        if(arr[x][j]){
            return false;
        }
    }
    
    // for primary diagonal
    for(int i = x, j = y; i >= 0 && j >= 0; i--, j--){
        if(arr[i][j]){
            return false;
        }
    }

    // for secondary diagonal
    for(int i = x, j = y; i < n && j >= 0; i++, j--){
        if(arr[i][j]){
            return false;
        }
    }

    return true;
}

void solveNQueens(vector<Vi> &chess, int y){
    int n = chess.size();

    if(y == n){
        displayMatrix(chess);
        cout<<"\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if(possible(chess, i, y)){
            chess[i][y] = 1;
            solveNQueens(chess, y+1);
            chess[i][y] = 0;
        }
    }
}

void solve(){
    optimize();
    
    int n;
    cin>>n;
    vector<Vi> chess(n, Vi(n, 0));

    solveNQueens(chess, 0);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}