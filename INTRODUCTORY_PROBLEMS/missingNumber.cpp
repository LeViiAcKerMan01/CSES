#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool arr[n+1] = {false};
    int temp;
    for(int i = 0; i < n-1; i++){
        cin >> temp;
        arr[temp] = true;
    }

    for(int i = 0; i < n; i++){
        if(arr[i+1] == false){
            cout<<i+1<<endl;
            break;
        }
    }
}