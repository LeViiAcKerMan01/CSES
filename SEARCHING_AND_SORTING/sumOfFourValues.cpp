#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, target;
    cin >> n >> target;

    ll a[n] = {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // O(n ^ 2)
    map<ll, pair<ll, ll>> mp;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll pair_sum = a[i] + a[j];
            ll complement = target - pair_sum;
            if(mp.find(complement) != mp.end()){
                cout<<mp[complement].first + 1<<" "<<mp[complement].second + 1<<" "<<i + 1<<" "<<j + 1<<'\n';
                // If we found the four values, the index gets printed and we exit the program
                return 0;
            }
        }
        for(int k = 0; k <= i - 1; k++){
            ll pair_sum = a[k] + a[i];
            mp[pair_sum] = {k, i};
        } 
    }
    // If we don't find the sum of four values equal to target, only then we come out of loops
    // We print Impossible therefore!!
    cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}