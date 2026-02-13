#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> v(n, 0);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<ll> prefixArray(n, 0);
    for(int i = 0; i < n; i++){

        prefixArray[i] = v[i];

        if(i){
            prefixArray[i] += prefixArray[i-1];
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        l = l-1;
        r = r-1;

        if(l){
            cout<<prefixArray[r] - prefixArray[l-1]<<'\n';
        }else{
            cout<<prefixArray[r]<<'\n';
        }
        
    }
}