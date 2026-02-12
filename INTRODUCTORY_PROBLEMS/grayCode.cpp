#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll binaryToGray(string s){
    ll n = s.size();
    for(int i = 0; i < n; i++){

    }
}
void printBinary(int n){

    ll total = (1 << n);

    for(ll mask = 0; mask < total; mask++){

        int gray = mask ^ (mask / 2);
        for(ll i = n-1; i >= 0; i--){
            cout<<((gray >> i) & 1);
        }
        cout<<'\n';
    }
}
int main(){
    int n;
    cin >> n;
    printBinary(n);
}