#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    
    vector<ll> arr(n, 0);
    
    // vector creation
    for(int i = 0; i < n; i++){
        if(i == 0){
            arr[i] = x;
        }
        else{
            arr[i] = (a * arr[i-1] + b) % c;
        }
    }

    // prefix ORs
    vector<ll> pf_ors(n);

    for(int i = 0; i < n; i++){
        if(i % k == 0){
            pf_ors[i] = arr[i];
        }
        else{
            pf_ors[i] = pf_ors[i-1] | arr[i];
        }
    }

    // suffix ORs
    vector<ll> sf_ors(n);
    sf_ors[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        if(i % k == k-1){
            sf_ors[i] = arr[i];
        }
        else{
            sf_ors[i] = arr[i] | sf_ors[i+1]; 
        }
    }

    // storing and printing the answer
    ll ans = 0;

    for(int j = k-1; j < n; j++){
        ll curOR = pf_ors[j] | sf_ors[j-k+1];
        ans ^= curOR;
    }

    cout<<ans<<"\n";
}