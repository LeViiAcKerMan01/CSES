#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n, 0);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> freq(k+1, 0);
    set<int> missing;


    for(int i = 0; i <= k; i++){
        missing.insert(i);
    }

    // checking missing element for the first window
    for(int i = 0; i < k; i++){
        if(a[i] <= k){
            freq[a[i]]++;
            if(freq[a[i]] == 1){
                missing.erase(a[i]);
            }
        }
    }
    // printing the first mex of the first window
    cout<<*(missing.begin())<<" ";

    for(int i = k; i < n; i++){

        // removing the outgoing element from the given window
        if(a[i-k] <= k){
            freq[a[i-k]]--;
            if(freq[a[i-k]] == 0){
                missing.insert(a[i-k]);
            }
        }

        // adding the upcoming element in the window
        if(a[i] <= k){
            freq[a[i]]++;
            if(freq[a[i]] == 1){
                missing.erase(a[i]);
            }
        }
        // printing the MEX element in the sliding window
        cout<<*(missing.begin())<<" ";
    }
}