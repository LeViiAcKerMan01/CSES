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
    bool flag = false;
    // O(n ^ 2)
    map<ll, ll> mp;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ll X = a[i];
            ll Y = a[j];
            ll findSum = target - (X + Y);
            if(mp.find(findSum) != mp.end()){
                flag = true;
                cout<<i+1<<" "<<j+1<<" "<<mp[findSum]+1<<'\n';
                return 0;
            }
            
        }
        mp[a[i]] = i; 
    }
    if(!flag){
        cout<<"IMPOSSIBLE"<<'\n';
    }
    return 0;
}