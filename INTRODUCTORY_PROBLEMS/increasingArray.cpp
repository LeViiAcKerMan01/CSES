#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n;
    cin >> n;
    int arr[n] = {0};
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long minMoves = 0;
    int runMax = INT_MIN;
    for(ll i = 0; i < n; i++){
        runMax = max(runMax, arr[i]);
        if(runMax > arr[i]){
            minMoves += (runMax - arr[i]);
        }
    }

    cout<<minMoves<<endl;
}


// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// int main(){
//     int n;
//     cin >> n;
//     int arr[n] = {0};
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     unsigned long long minMoves = 0;
//     for(ll i = 0; i < n; i++){
//         for(ll j = i+1; j < n; j++){
//             if(arr[i] > arr[j]){
//                 minMoves += (arr[i] - arr[j]);
//                 arr[j] += (arr[i] - arr[j]);
//             }else{
//                 continue;
//             }
//         }
//     }

//     cout<<minMoves<<endl;
// }
