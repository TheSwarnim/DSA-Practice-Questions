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

int largestAreaHistogram(Vi &arr, int n){
    stack<int> st;

    Vi lb(n);  //next smallest element index to the left to the i'th element

    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[i] <= arr[st.top()] ){
            st.pop();
        }

        if(st.empty()){
            lb[i] = -1;
        }else{
            lb[i] = st.top();
        }
        st.push(i);
    }
    
    while(!st.empty()) st.pop();

    Vi rb(n);  //next smallest element index to the left to the i'th element

    for (int i = n-1; i >= 0; i--)
    {
        while(!st.empty() && arr[i] <= arr[st.top()] ){
            st.pop();
        }

        if(st.empty()){
            rb[i]=n;
        }else{
            rb[i]=st.top();
        }
        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = rb[i] - lb[i] - 1;
        int area = arr[i] * width;

        maxArea = max(maxArea, area);
    }
    
    return maxArea;
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
    
    cout<<largestAreaHistogram(arr, n)<<endl;
    
    calcTime;
}

int main(){
    solve();

    return 0;
}