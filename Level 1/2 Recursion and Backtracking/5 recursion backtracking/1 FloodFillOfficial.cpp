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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1}; // right, top, left, down
char dir[] = {'t', 'l', 'd', 'r'};

void floodfill(vector<vector<int>> &maze, int x=0, int y=0, string path="") {
    if(x==-1 or x==maze.size() or y==-1 or y==maze[0].size() or maze[x][y]==1){
        return;
    }

    // base case
    if(x==maze.size()-1 && y==maze[0].size()-1){
        cout<<path<<"\n";
        return;
    }

    maze[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        floodfill(maze, x+dx[i], y+dy[i], path+dir[i]);
    }
    maze[x][y] = 0;
}

void solve(){
    optimize();
    
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    floodfill(arr);

    calcTime;
}

int main(){
    solve();

    return 0;
}
