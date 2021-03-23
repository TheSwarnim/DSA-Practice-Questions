#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    int outerspace = n/2;
    int innerspace = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=outerspace; j++){
            cout<<"\t";
        }

        cout<<"*";

        for(int j=1; j<=innerspace; j++){
            cout<<"\t\t";
        }
        
        if(i!=1 && i!=n) cout<<"*";

        if(i<=n/2){
            outerspace--;
            innerspace++;
        }else{
            outerspace++;
            innerspace--;
        }
        cout<<"\n";
    }

    return 0;
}