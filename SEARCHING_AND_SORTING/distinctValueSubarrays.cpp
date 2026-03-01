#include<bits/stdc++.h>
using namespace std;
#define  ll long 


int main(){

    ll n;
    cin >> n;
    ll a[n] = {0};

    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    map<ll, ll> freq;

    ll left = 0;
    ll cnt = 0;

    for(ll right = 0; right < n; right++){
        freq[a[right]]++;
        
        // Till the time the freq of the right element is greater than 1
        // reduce its frequency by 1, until it becomes one of distinct
        while(freq[a[right]] > 1){
            freq[a[left]]--;
            left++;
        }
        // subarrays ending at right pointer having all distinct elements
        // will be (right - left + 1)
        cnt += (right - left + 1);
    }
    cout<<cnt<<'\n';
}