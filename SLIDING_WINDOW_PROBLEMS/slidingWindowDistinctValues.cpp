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
    vector<ll> v(n, 0);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    map<ll, ll> mp;

    vector<ll> XORR;
    int size = 0;
    
    for(int i = 0; i < k; i++){
        mp[v[i]]++;
        // size++;
    }
    XORR.push_back(mp.size());  

    if(k < n){
        for(int i = k; i < n; i++){
            mp[v[i]]++;
            // size++;

            if(mp[v[i-k]] > 1){
                mp[v[i-k]]--;
                if(mp[v[i-k]] == 0){
                    mp.erase(v[i-k]);
                }
            
            }else{
                mp.erase(v[i-k]);
            }

            XORR.push_back(mp.size());
        }
    }

    for(auto it : XORR){
        cout<<it<<" ";
    }

    // ll res = 0;
    // for(auto it : XORR){
    //     res ^= it;
    // }
    // cout<<res<<" ";
}