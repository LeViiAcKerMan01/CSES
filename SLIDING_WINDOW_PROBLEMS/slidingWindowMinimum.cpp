// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int

// ll modAdd(ll a, ll b, ll mod){
//     ll res = ((a % mod) + (b % mod)) % mod;
//     return res;
// }

// int main(){

//     // T.C : O(n log k)
//     // S.C : O(k + n)
//     ll n, k;
//     cin >> n >> k;

//     ll x, a, b, c;
//     cin >> x >> a >> b >> c;

//     vector<ll> v(n+1, 0);
//     v[1] = x;

//     for(int i = 2; i <= n; i++){
//         ll temp = a * v[i-1];
//         v[i] = modAdd(temp, b, c);
//     }
//     // To find the minimum in every window of size k
//     // create a priority queue
//    multiset<ll> s;
//     vector<ll> XORR;

//     for(int i = 1; i <= k; i++){
//         s.insert(v[i]);
//     }
//     XORR.push_back(*(s.begin()));
//     for(int i = k+1; i <= n; i++){
//         s.erase(s.find(v[i-k]));
//         s.insert(v[i]);
//         XORR.push_back(*(s.begin()));
//     }
//     ll ans = 0;

//     // for(auto it : XORR){
//     //     cout<<it<<" ";
//     // }
//     // The property of XOR is that
//     // 0 XORRED with any integer lends the integer itself
//     int m = XORR.size();
//     for(int i = 0; i < m; i++){
//         ans ^= XORR[i];
//     }
//     cout<<ans<<'\n';
// }


// O(n) approach exists using DEQUE(monotonic queue)
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
    deque<ll> dq;
    // monotonic queue
    vector<ll> ans;

    for(int i = 0; i < n; i++){

        // remove the index that is out of the current window
        while(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }

        // if the current element is smaller
        while(!dq.empty() && v[dq.back()] >= v[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        // if the window is complete, push the minimum in the window to the answer vector
        if(i >= k-1){
            ans.push_back(v[dq.front()]);
        }
    }

    ll result = 0;
    for(auto it : ans){
        result ^= it;
    }
    cout<<result<<'\n';
}
