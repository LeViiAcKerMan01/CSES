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
    // To find the minimum in every window of size k
    // create a priority queue
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<ll> XORR;

    for(int i = 1; i <= k; i++){
        pq.push(v[i]);
    }
    XORR.push_back(pq.top());
    for(int i = k+1; i <= n; i++){
        if(v[i-k] == pq.top()){
            pq.pop();
        }
        pq.push(v[i]);
        XORR.push_back(pq.top());
    }
    ll ans = 0;
    // The property of XOR is that
    // 0 XORRED with any integer lends the integer itself
    for(int i = 1; i <= n; i++){
        ans ^= XORR[i];
    }
    cout<<ans<<'\n';

    
}