#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> L(n), R(n);
    stack<int> st;

    // Previous smaller element
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        L[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    // Next smaller element
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] >= a[i])
            st.pop();
        R[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    vector<ll> ans(n - k + 1, 0);

    // Each bar contributes to a range of windows
    for(int i = 0; i < n; i++) {

        int leftLimit = L[i] + 1;
        int rightLimit = R[i] - 1;

        if(rightLimit - leftLimit + 1 < k)
            continue;  // cannot fit a full window

        int startWindow = leftLimit;
        int endWindow = rightLimit - k + 1;

        startWindow = max(startWindow, 0);
        endWindow = min(endWindow, n - k);

        for(int w = startWindow; w <= endWindow; w++) {
            ans[w] = max(ans[w], a[i] * 1LL * k);
        }
    }

    for(ll x : ans)
        cout << x << " ";
}