#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[n] = {0};

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    // this takes TC : O( N logN)
    ll median = a[n / 2];

    ll minCost = 0;
    for(int i = 0; i < n; i++){
        minCost += abs(a[i] - median);
    }
    cout<<minCost<<'\n';    
}