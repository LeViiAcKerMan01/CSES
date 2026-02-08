#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin >> n;
    ll cnt = 0;
    vector<ll> arr(n, 0);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
        
    }
    for(ll i = 0; i < n; i++){
        if(arr[i] == i+1 && i != 0 && i != n-1){
            bool flag = false;
            if(i >= (n-i)){
                for(int j = i+1; j < n; j++){
                    if(arr[j] < arr[i]){
                        flag = true;
                        break;
                    }
                }
            }
            else{
                for(int j = 0; j < i; j++){
                    if(arr[j] > arr[i]){
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag){
                cnt++;
            }
        }
    }
    if(arr[0] == 1){
        cnt++;
    }
    if(arr[n-1] == n){
        cnt++;
    }
    cout<<cnt<<endl;
}