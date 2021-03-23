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

bool balancedBrackets(string str){
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str.at(i);

        if(ch=='(' || ch=='[' || ch=='{'){
            st.push(ch);
        }else if(ch==')'){
            if(st.size()==0 || st.top()!='('){
                return false;
            }else{
                st.pop();
            }
        }else if(ch==']'){
            if(st.size()==0 || st.top()!='['){
                return false;
            }else{
                st.pop();
            }
        }else if(ch=='}'){
            if(st.size()==0 || st.top()!='{'){
                return false;
            }else{
                st.pop();
            }
        }
    }
    return st.size()==0?true:false;
}

void solve(){
    optimize();

    string str;
    getline(cin, str);
    cout << boolalpha << balancedBrackets(str);
    
    calcTime;
}

int main(){
    solve();

    return 0;
}