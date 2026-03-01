#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n, 0);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    stack<pair<ll, ll>> st;
    vector<ll> ans(n, 0);
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top().first >= a[i]){
            st.pop();
        }
        // Only if stack is not empty
        // It implies that some value smaller than current value exists to the left!!
        // Otherwise, it is 0 by itself!!
        if(!st.empty()){
            ans[i] = st.top().second;
        }
        st.push({a[i], i+1});
    }
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
      
}