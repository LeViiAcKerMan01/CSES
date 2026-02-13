#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll modAdd(ll a, ll b, ll mod){
    ll res = ((a % mod) + (b % mod)) % mod;
    return res;
}
int main(){
    ll n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> v(n+1, 0);
    v[1] = x;

    for(int i = 2; i <= n; i++){
        ll temp = a * v[i-1];
        v[i] = modAdd(temp, b, c);
    }

    // for(int i = 1; i <= 8; i++){
    //     cout<<v[i]<<" ";
    // }
    vector<ll> XORR;
    ll sum = 0;
    for(int i = 1; i <= k; i++){
        sum += v[i];
    }
    XORR.push_back(sum);

    for(int i = k+1; i <= n; i++){
        sum += v[i];
        sum -= v[i-k];  
        XORR.push_back(sum);
    }

    // for(auto it : XORR){
    //     cout<<it<<" ";
    // }
    ll m = XORR.size();
    ll ans = 0;
    for(ll i = 0; i < m; i++){
        ans ^= XORR[i];
    }
    cout<<ans<<'\n';
}