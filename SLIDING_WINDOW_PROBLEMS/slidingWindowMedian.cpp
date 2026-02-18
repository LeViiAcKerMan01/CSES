#include<bits/stdc++.h>
using namespace std;

void rebalance(multiset<long long> &low, multiset<long long> &high){
    while(low.size() > high.size() + 1){
        auto it = prev(low.end());
        high.insert(*it);
        low.erase(it); 
    }
    while(high.size() > low.size()){
        auto it = high.begin();
        low.insert(*it);
        high.erase(it);
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    multiset<long long> low, high;

    // Searching the median for the first window
    for(int i = 0; i < k; i++){
        if(low.empty() || a[i] <= *prev(low.end())){
            low.insert(a[i]);   
        }else{
            high.insert(a[i]);
        }

        // To check if any of the condition arises, that are to be fixed
        rebalance(low, high);
    }
    

    // printing the median in the first window
    cout<<*prev(low.end())<<" ";


    for(int i = k; i < n; i++){
        
        long long remove_val = a[i-k];
        // removing the outgoing element from any of the one heap
        
        // SAFE REMOVAL TECHNIQUE - To overcome runtime error
        auto it = low.find(remove_val);
        if(it != low.end()){
            low.erase(it);
        }
        else{
            high.erase(high.find(remove_val));
        }
        rebalance(low, high);

        // adding the incoming element in any one of the heap
        if(low.empty() || a[i] <= *prev(low.end())){
            low.insert(a[i]);
        }
        else{
            high.insert(a[i]);
        }

        // To check if any of the condition arises, that are to be fixed
        rebalance(low, high);


        // printing the median in the running window
        cout<< *prev(low.end())<<" ";
    }
}