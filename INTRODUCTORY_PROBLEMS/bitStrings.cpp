#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// To find x^n
ll binPow(ll x, ll n, ll m){
    ll res = 1;

    while(n > 0){
        if(n % 2 != 0){
            res *= (x % m);
            res %= m;
        }
        x = (x * x) % m;
        n /= 2;
    }
    return res%m;
}

int main(){
    int n;
    cin >> n;
    int m = 1e9+7;
    ll totalBinaryStrings = binPow(2, n, m);
    cout<<totalBinaryStrings<<endl;
}