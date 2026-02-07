#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n;
    cin >> n;

    for(int k = 1; k <= n; k++){
        ll totalWays = (pow(k, 2) * (pow(k, 2)-1)) / 2;
        ll attackingWays = 4 * (k-1) * (k-2);

        ll possibleWays = totalWays - attackingWays;
        cout<<possibleWays<<"\n";
    }
}