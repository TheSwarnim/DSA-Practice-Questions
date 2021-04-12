#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>

bool debug;
void optimize(){
    if(debug){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        #endif
    }
}

void calcTime(){
    if(debug){
        cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    }
}

void solve(){
    string str, oprants;
    cin>>str>>oprants;

    int n = str.size();

    vvi t(n, vi(n));
    vvi f(n, vi(n));
    for (int g = 0; g < n; g++)
    {
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0){
                if(str.at(i) == 'T'){
                    t[i][j] = 1;
                    f[i][j] = 0;
                } else{
                    t[i][j] = 0;
                    f[i][j] = 1;
                }
            } else{
                for(int k = i; k < j; k++){
                    char oprtr = oprants.at(k);
                    int ltc = t[i][k];
                    int rtc = t[k+ 1][j];
                    int lfc = f[i][k];
                    int rfc = f[k+ 1][j];
                    
                    
                    switch(oprtr){
                        case '&':
                            t[i][j] += (ltc * rtc);
                            f[i][j] += (lfc * rfc + lfc * rtc + ltc * rfc);
                            break;
                        case '|':
                            t[i][j] += (ltc * rtc + lfc * rtc + ltc * rfc);
                            f[i][j] += (lfc * rfc);
                            break;
                        case '^':
                            t[i][j] += (ltc * rfc + lfc * rtc);
                            f[i][j] += (ltc * rtc + lfc * rfc);
                            break;
                    }
                }
            }
        }
    }
    cout << t[0][n - 1] << endl;
}

int main(){
    debug = true;
    optimize();
    
    solve();

    calcTime();
    return 0;
}