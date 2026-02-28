#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const ll MAX_N = 1000000;
ll divisors[MAX_N + 1];
int mod = 1e9 + 7;

void precomputeDivisors(){
    for(ll i = 1; i <= MAX_N; i++){
        for(ll j = i; j <= MAX_N; j += i){
            divisors[j] = (divisors[j] + i) % mod;
        }
    }
}

int main(){
    precomputeDivisors();
    ll n;
    cin >> n;
    

    cout<<divisors[n]<<'\n';
}