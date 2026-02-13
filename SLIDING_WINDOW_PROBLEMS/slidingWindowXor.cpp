#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll modAdd(ll a, ll b, ll mod){
    ll res = ((a % mod) + (b % mod)) % mod;
    return res;
}

int main(){
    ll n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> v(n, 0);
    v[0] = x;

    for(int i = 1; i < n; i++){
        ll temp = a * v[i-1];
        v[i] = modAdd(temp, b, c);
    }

    ll temp = 0;
    vector<ll> XORR;

    for(int i = 0; i < k; i++){
        temp ^= v[i];
    }
    XORR.push_back(temp);

    for(int i = k; i < n; i++){
        temp ^= v[i-k];
        temp ^= v[i];

        XORR.push_back(temp);
    }

    ll res = 0;

    for(auto it : XORR){
        res ^= it;
    }
    cout<<res<<'\n';

}