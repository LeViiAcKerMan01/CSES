#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int,int> freq;
    set<pair<int,int>> st; 
    // (frequency, -value)

    // First window
    for (int i = 0; i < k; i++) {
        int val = a[i];

        if (freq[val] > 0) {
            st.erase({freq[val], -val});
        }

        freq[val]++;
        st.insert({freq[val], -val});
    }

    // Print mode of first window
    cout << -st.rbegin()->second << " ";

    // Slide window
    for (int i = k; i < n; i++) {
        int add = a[i];
        int remove = a[i-k];

        // Remove outgoing element
        st.erase({freq[remove], -remove});
        freq[remove]--;
        if (freq[remove] > 0) {
            st.insert({freq[remove], -remove});
        }

        // Add incoming element
        if (freq[add] > 0) {
            st.erase({freq[add], -add});
        }
        freq[add]++;
        st.insert({freq[add], -add});

        // Output current mode
        cout << -st.rbegin()->second << " ";
    }

    return 0;
}
