// we have to find two values at distinct positions whose values is x
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n, Sum;
    cin >> n >> Sum;

    vector<pair<ll, ll>>a(n);
    ll temp;

    for(int i = 0; i < n; i++){
        cin >> temp;
        a[i] = {temp, i+1};
    }
    ll l = 0, r = n-1;
    sort(a.begin(), a.end());
    bool found = false;

    while(l < r){
        ll sum = a[l].first + a[r].first;

        if(sum == Sum){
            found = true;
            cout<<a[l].second<<" "<<a[r].second<<'\n';
            return 0;
        }
        else if(sum < Sum){
            l++;
        }
        else{
            r--;
        }
    }
    cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}