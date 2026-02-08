#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin >> n;
    // bool arr[n+1] = {false};
    ll temp;
    set<int> s;
    for(ll i = 0; i < n; i++){
        cin >> temp;
        s.insert(temp);
    }
    

    cout<<s.size()<<endl;
}