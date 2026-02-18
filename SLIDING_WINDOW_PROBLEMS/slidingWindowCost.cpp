#include<bits/stdc++.h>
using namespace std;
#define ll long long

void rebalance(multiset<ll> &low, multiset<ll> &high, ll &sumLow, ll &sumHigh){
    while(low.size() > high.size() + 1){
        auto it = prev(low.end());
        ll val = *it;
        
        high.insert(val);
        sumHigh += val;

        low.erase(it); 
        sumLow -= val;
    }
    while(high.size() > low.size()){

        auto it = high.begin();
        ll val = *it;

        high.erase(it);
        sumHigh -= val;

        low.insert(val);
        sumLow += val;
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;  

    vector<ll> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    multiset<ll> low, high;

    ll sumLow = 0, sumHigh = 0;

    // Searching the median for the first window
    for(int i = 0; i < k; i++){
        if(low.empty() || a[i] <= *prev(low.end())){
            low.insert(a[i]);
            sumLow += a[i];  
        }else{
            high.insert(a[i]);
            sumHigh += a[i];
        }

        // To check if any of the condition arises, that are to be fixed
        rebalance(low, high, sumLow, sumHigh);

    }
    ll m = *prev(low.end());
    ll cost = m * low.size() - sumLow + sumHigh - m * high.size();
    // printing the median in the first window
    cout<<cost<<" ";


    for(int i = k; i < n; i++){
        
        ll remove_val = a[i-k];
        // removing the outgoing element from any of the one heap
        
        // SAFE REMOVAL TECHNIQUE - To overcome runtime error
        auto it = low.find(remove_val);
        if(it != low.end()){
            low.erase(it);
            sumLow -= remove_val;
        }
        else{
            auto it2 = high.find(remove_val);
            
            if(it2 != high.end()){
                high.erase(it2);
                sumHigh -= remove_val;
            }
        }
        // rebalance even after the removal of an element
        rebalance(low, high, sumLow, sumHigh);

        
        // adding the incoming element in any one of the heap
        if(low.empty() || a[i] <= *prev(low.end())){
            low.insert(a[i]);
            sumLow += a[i];
        }
        else{
            high.insert(a[i]);
            sumHigh += a[i];
        }

        // To check if any of the condition arises, that are to be fixed
        rebalance(low, high, sumLow, sumHigh);



        m = *prev(low.end());
        cost = m * low.size() - sumLow + sumHigh - m * high.size();  
        // printing the median in the first window
        cout<<cost<<" ";
    }
}

// long long cost = m * low.size() - sumLow + sumHigh - m * high.size();