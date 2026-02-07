#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin >> n;
    // int arr[n];
    set<ll> s1, s2;
    ll tSum = 0;
    tSum = (n * (n+1)) / 2;
    bool arr[n+1] = {false};

    if(tSum % 2){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        ll findSum = tSum / 2;
        for(int i = n; i >= 1; i--){
            if(findSum >= i){
                s1.insert(i);
                findSum -= i;
                arr[i] = true;
            }
        }
        cout<<s1.size()<<endl;
        for(auto it : s1){
            cout<<it<<" ";
        }
        // cout<<"\n";
        for(int i = 1; i <= n; i++){
            if(arr[i] == false){
                s2.insert(i);
            }
        }
        cout<<"\n";
        cout<<s2.size()<<endl;
        for(auto it : s2){
            cout<<it<<" ";
        }
    }
}