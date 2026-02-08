#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    
    ll minDiff = INT_MAX;
    for(ll mask = 0; mask < (1 << n); mask++){
        ll sumA = 0;
        ll sumB = 0;

        for(ll position = 0; position < n; position++){
            if(mask & (1 << position)){
                sumA += arr[position];
            }else{
                sumB += arr[position];
            }
        }
        minDiff = min(minDiff, abs(sumA - sumB));
    }

    cout<<minDiff<<endl;
}