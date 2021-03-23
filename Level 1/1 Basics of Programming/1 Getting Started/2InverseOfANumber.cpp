#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    int i = 0; // inverted number
    int p = 1; // position
    // in inverted num (pos -> number => number -> pos)
    while(n){
        int dig = n%10;
        i += p * pow(10, dig-1);

        n/=10;
        p++;
    }

    cout << (i) << endl;
}