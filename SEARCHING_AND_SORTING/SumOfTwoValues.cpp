#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n, x;
    cin >> n >> x;

    vector<ll> v(n, 0);
    vector<ll> temp(v);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int j = 0, k = n-1;
    bool flag = false;
    while(j < k){
        if(v[j] + v[k] == x){
            ll a = 0, b = 0;
            for(int i = 0; i < n; i++){
                if(temp[i] == v[j]){
                    a = i+1;
                    temp[i] = -1;
                }
                if(temp[i] == v[k]){
                    b = i+1;
                    temp[i] = -1;
                }
            }
            cout<<a<<" "<<b<<endl;
            flag = true;
            break;
        }else if(v[j] + v[k] < x){
            j++;
        }else if(v[j] + v[k] > x){
            k--;
        }
    }
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
    }

}