#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int temp;
    vector<bool> visited(n+1, false);

    for(int i = 0; i < n; i++){
        cin >> temp;
        arr[i] = temp;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
       bool tempCheck = false;
        if(!visited[arr[i]]){
            tempCheck = true;
            for(int j = i+1; j < n; j++){
                if(arr[j] > arr[i] && !visited[arr[j]]){
                    visited[arr[j]] = true;
                }
            }
            if(tempCheck){
            cnt++;
            }
        }
        
    }

    cout<<cnt<<endl;


}