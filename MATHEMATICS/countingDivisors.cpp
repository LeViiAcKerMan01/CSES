#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int MAX_N = 1000000;

int main(){
    int n;
    cin >> n;
    vector<int> freq(MAX_N + 1, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    for(int d = MAX_N; d >= 1; d--){

        int count = 0;

        for(int multiples = d; multiples <= MAX_N; multiples += d){
            
            // count will only increase if the multiple
            // of that number is present in the array
            count += freq[multiples];
            if(count >= 2){
                cout<<d<<'\n';
                return 0;
            }
        }
    }
    return 0;
}