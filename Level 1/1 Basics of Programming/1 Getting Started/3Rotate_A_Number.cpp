#include <iostream>
#include<cmath>

using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    
    //write your code here
    int temp=n;
    int cnt=0;
    while(temp) cnt++, temp/=10;
    k %= cnt;
    if(k<0) k = k + cnt;

    int div = n%(int)pow(10, k);
    int quo = n/(int)pow(10, k);

    // cout << div << " " << quo << " " << (int)pow(10, cnt-k);
    cout<< quo + div*(int)pow(10, cnt-k) << endl;
}