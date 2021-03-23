#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)1e9+7;
#define test ll t;cin>>t;while(t--)
#define endl "\n"
#define pb push_back
#define vll vector<ll>
#define VP vector<pair<ll,ll>>
#define pf push_front
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lp(i,a,b) for(ll i=a;i<=b;i++)
#define rlp(i,a,b) for(ll i=a;i>=b;i--)
#define read(type,x) type x;cin>>x;
#define scanint(x) int x;cin>>x;
#define scanll(x) ll x;cin>>x;
#define scanstr(str) string str;cin>>str;
#define scanchr(chr) char chr;cin>>chr;
#define all(c) (c).begin(), (c).end()
#define vecread(vec) for(auto &x:vec){cin>>x;}
#define calcTime cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
#define debug(a) cout<<a<<endl;
#define debug2(a,b) cout<<a<<" "<<b<<endl;
#define debug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
#define joker(V) for(auto X:V)cout<<X<<" ";cout<<endl;
#define papiya(Mp) for(auto X:Mp)cout<<X.first<<" "<<X.second<<endl;


void solve(){
    scanint(n)
    if(n<2) return;
    vector<bool> prime(n+1, true);
    vector<int> listPrimes;
    for(int i=2; i<=n; i++){
        // debug(i)
        if(prime[i]){
            listPrimes.pb(i);
            for(int j=i*i; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }
    joker(listPrimes)
    
}

int main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    //test
    //{
        solve();
    //}

    calcTime;
    return 0;
}