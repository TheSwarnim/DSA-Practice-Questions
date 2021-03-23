#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }

    int minr = 0, minc = 0;
    int maxr = n-1, maxc = m-1;
    int ttlEle = n*m;
    int cnt = 0;

    while(cnt<ttlEle){
        // left wall
        for(int i=minr, j=minc; i<=maxr && cnt<ttlEle; i++){
            cout<<a[i][j]<<endl;
            cnt++;
        }

        minc++;
        // bottom wall
        for(int i=maxr, j=minc; j<=maxc && cnt<ttlEle; j++){
            cout<<a[i][j]<<endl;
            cnt++;
        }

        maxr--;
        // right wall
        for(int i=maxr, j=maxc; i>=minr && cnt<ttlEle; i--){
            cout<<a[i][j]<<endl;
            cnt++;
        }

        maxc--;
        // top wall
        for(int i=minr, j=maxc; j>=minc && cnt<ttlEle; j--){
            cout<<a[i][j]<<endl;
            cnt++;
        }

        minr++;
    }
}

int main(){
    solve();

    return 0;
}
