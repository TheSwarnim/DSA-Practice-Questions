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

void printKnightsTour(vector<vector<int>> &chess, int r, int c, int moveNo){
    int n = chess.size();

    // handle base case
    if(r<0 || c<0 || r>=n || c>=n || chess[r][c]>0){
        return;
    }else if(moveNo==n*n){
        chess[r][c] = moveNo;
        displayMatrix(chess);
        cout<<"\n";
        chess[r][c] = 0;
        return;
    }

    chess[r][c] = moveNo;
    printKnightsTour(chess, r - 2, c + 1 , moveNo + 1);
    printKnightsTour(chess, r - 1, c + 2 , moveNo + 1);
    printKnightsTour(chess, r + 1, c + 2 , moveNo + 1);
    printKnightsTour(chess, r + 2, c + 1 , moveNo + 1);
    printKnightsTour(chess, r + 2, c - 1 , moveNo + 1);
    printKnightsTour(chess, r + 1, c - 2 , moveNo + 1);
    printKnightsTour(chess, r - 1, c - 2 , moveNo + 1);
    printKnightsTour(chess, r - 2, c - 1 , moveNo + 1);
    chess[r][c] = 0;
}

void solve(){
    optimize();
    
    int n;cin>>n;

    vector<vector<int>> arr(n, vector<int>(n, 0));

    int x, y;
    cin>>x>>y;

    // arr[x][y] = 1;
    printKnightsTour(arr, x, y, 1);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}