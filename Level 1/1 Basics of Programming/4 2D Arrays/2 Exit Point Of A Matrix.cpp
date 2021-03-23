#include<bits/stdc++.h>
using namespace std;

enum Directions{
    east,
    south,
    west,
    north,
};

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

    int directions=0;
    int i=0;
    int j=0;

    while(true){
        directions = (directions + a[i][j])%4;

        if(directions==Directions::east){
            j++;
        }else if(directions==Directions::south){
            i++;
        }else if(directions==Directions::west){
            j--;
        }else if(directions==Directions::north){ 
            i--;
        }
        // cout<<i<<" "<<j<<endl;
        
        if(i<0){
            i++;
            break;
        }
        else if(j<0){
            j++;
            break;
        }
        else if(i==n){
            i--;
            break;
        }
        else if(j==m){
            j--;
            break;
        }
    }

    cout<<i<<"\n"<<j<<"\n";
}

int main(){
    solve();

    return 0;
}
