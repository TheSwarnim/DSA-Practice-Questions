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

void SlidingWindowMaximum(Vi &arr, int n, int k){
    stack<int> st;
    Vi nge(n); //next greater element

    for (int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && arr[st.top()] <= arr[i] ){
            st.pop();
        }

        if(st.empty()){
            nge[i]=n;
        }else{
            nge[i]=st.top();
        }

        st.push(i);
    }
    
    int j=0;
    for (int i = 0; i <= n-k; i++)
    {
        // enter the loop to find the maximum of window starting at i
        if(j<i) j=i;

        while(nge[j]<i+k){
            j=nge[j];
        }

        printf("%d\n", arr[j]);
    }
    
}

void solve(){
    optimize();

    int n;
    cin>>n;
    
    Vi arr(n);
    for (auto &&i : arr)
    {
        cin>>i;
    }

    int k;
    cin>>k;
    
    SlidingWindowMaximum(arr, n, k);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}