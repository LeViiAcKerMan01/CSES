#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> arr(n, 0);
    int maxi = INT_MIN;
    int mini = INT_MAX;

    vector<int> prefixMax(n, 0);

    vector<int> suffixMin(n, 0);

    
    for(int i = 0; i < n; i++){
        cin >> arr[i];

        maxi = max(maxi, arr[i]);
        prefixMax[i] = maxi;
    }

    for(int i = n-1; i >= 0; i--){
        mini = min(mini, arr[i]);
        suffixMin[i] = mini;
    }
    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(prefixMax[i] <= arr[i] && suffixMin[i] >= arr[i]){
            cnt++;
        }else{
            continue;
        }
    }
    cout<<cnt<<endl;
}