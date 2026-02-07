#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;

// void printPrimeFactors(int n){
//     if(n <= 1) return;
//     for(int i = 2; i * i <= n; i++){
//         int cnt = 0;
//         while(n % i == 0){
//             cnt++;
//             n = n / i;
//         }
//         if(cnt){
//             mp[i] = cnt;
//         }
//     }
//     if(n > 1){
//         mp[n]++;
//     }
// }

int trailingZeroes(int n){
    int res = 0;

    for(int i = 5; i <= n; i *= 5){
        res = res + (n / i);
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    // printPrimeFactors(n);

    // for(auto it : mp){
    //     cout<<it.first<<" -> "<<it.second<<endl;
    // }

    int trailZero = trailingZeroes(n);
    cout<<trailZero<<endl;

}