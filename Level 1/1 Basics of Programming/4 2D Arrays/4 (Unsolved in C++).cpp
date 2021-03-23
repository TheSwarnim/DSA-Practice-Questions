#include<bits/stdc++.h>
using namespace std;

void displayArray(vector<int> &arr){
    for (auto &&i : arr)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
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

vector<int> getIDShellVector(vector<vector<int>> &arr, int s){
    vector<int> ring;

    int minr = s-1, minc = s-1;
    int maxr = arr.size() - s, maxc = arr[0].size() -s;
    int ttl = (maxr - minr + 1)*2 + (maxc - minc + 1)*2 - 4;
    int cnt = 0;
    // left
    for(int i=minr, j=minc; i<=maxr && cnt<ttl; i++){
        ring.push_back(arr[i][j]);
        cnt++;
    }
    minc++;

    // bottom
    for(int i=maxr, j=minc; j<=maxc && cnt<ttl; j++){
        ring.push_back(arr[i][j]);
        cnt++;
    }
    maxr--;

    // right
    for(int i=maxr, j=maxc; i>=minr && cnt<ttl; i--){
        ring.push_back(arr[i][j]);
        cnt++;
    }
    maxc--;

    // up
    for(int i=minr, j=maxc; j>=minc && cnt<ttl; j--){
        ring.push_back(arr[i][j]);
        cnt++;
    }
    minr++;

    return ring;
}

void rotate1DVector(vector<int> &arr, int r){
    int n=arr.size();
    r %= n;
    if(r<0) r+=n;
    reverse(arr.begin(), arr.end()-r);
    reverse(arr.end()-r+1, arr.end());
    reverse(arr.begin(), arr.end());
}

void rearrangeMatrix(vector<vector<int>> &arr, vector<int> &ring, int s){
    int minr = s-1, minc = s-1;
    int maxr = arr.size() - s, maxc = arr[0].size() -s;
    int ttl = (maxr - minr + 1)*2 + (maxc - minc + 1)*2 - 4;
    int cnt = 0;
    // left
    for(int i=minr, j=minc; i<=maxr && cnt<ttl; i++){
        arr[i][j] = ring[cnt];
        cnt++;
    }
    minc++;

    // bottom
    for(int i=maxr, j=minc; j<=maxc && cnt<ttl; j++){
        arr[i][j] = ring[cnt];
        cnt++;
    }
    maxr--;

    // right
    for(int i=maxr, j=maxc; i>=minr && cnt<ttl; i--){
        arr[i][j] = ring[cnt];
        cnt++;
    }
    maxc--;

    // up
    for(int i=minr, j=maxc; j>=minc && cnt<ttl; j--){
        arr[i][j] = ring[cnt];
        cnt++;
    }
    minr++;
}

void ringRotate(vector<vector<int>> &arr, int s, int r){ //swapping the upper half of matrix
    vector<int> ring = getIDShellVector(arr, s);
    
    // displayMatrix(arr);
    // displayArray(ring);
    rotate1DVector(ring, r);
    displayArray(ring);
    rearrangeMatrix(arr, ring, s);
    // displayMatrix(arr);
}

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

    int s,r;
    cin>>s>>r; //rotate the 's'th ring by 'r' rotations and display the rotated matrix.

    ringRotate(a, s, r);
    displayMatrix(a);
}

int main(){
    solve();

    return 0;
}
