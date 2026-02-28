#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll binaryExponentiation(ll a, ll b, ll mod){
    ll res = 1;
    a %= mod;

    while(b){
        if(b &1){
            res = (res * a) % mod;
        }
        a =(a * a) % mod;
        b = b >> 1; // right shift by 2
    }
    return res;
}
int main(){
    int t;
    cin >> t;
    ll mod = 1e9+7;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll power = binaryExponentiation(a, b, mod);
        cout<<power<<'\n';
    }
}