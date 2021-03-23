#include <iostream>
#include<cmath>

using namespace std;

int getGCD(int n1, int n2){
    if(n2==0) return n1;
    int temp = n2;
    n2 = n1%n2;
    n1 = temp;
    return getGCD(n1, n2);
}

int getLCM(int n1, int n2, int gcd){
    return (n1/gcd) * n2;
}

int main(){
    int n,k;
    cin>>n>>k;
    
    //write your code here
    if(n<k) swap(n, k);

    int gcd = getGCD(n,k);
    int lcm = getLCM(n,k,gcd);

    cout<<gcd<<endl<<lcm<<endl;
}