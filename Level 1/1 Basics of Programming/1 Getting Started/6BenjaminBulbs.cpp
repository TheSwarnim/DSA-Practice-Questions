#include <bits/stdc++.h>

using namespace std;

int main(int argc, char**argv){
    int n;
    cin>>n;

    // all perfect squares have odd numbers of factors and rest have even
    
    //write your code here
    for(int i=1; i*i<=n; i++){
        cout<<i*i<<endl;
    }   
    
}