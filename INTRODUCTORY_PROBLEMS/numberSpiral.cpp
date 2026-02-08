#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll answer(ll x, ll y){

    ll mx = max(x, y);
    if(mx % 2 == 0){
        if(y == 1){
            return mx * mx;
        }
        else if(x < mx){
            return answer(mx, mx) - (mx - x); 
        }
        else if(x == mx){
            return mx * mx - (y-1);
        }
    }
    else{
        if(x == 1){
            return mx * mx;
        }
        else if(y < mx){
            return answer(mx, mx) - (mx - y);
        }
        else if(y == mx){
            return (mx * mx) - (x - 1);
        }
    }
}
void solve(){
    ll x, y;
    cin >> x >> y;
    cout<<answer(x, y)<<"\n";
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}