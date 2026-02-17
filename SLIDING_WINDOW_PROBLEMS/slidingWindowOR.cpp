#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Add number to window
void add_number(ll x, vector<int> &bit_count, ll &current_or) {
    for (int i = 0; i < 31; i++) {
        if (x & (1LL << i)) {
            bit_count[i]++;
            if (bit_count[i] == 1) {
                current_or |= (1LL << i);  // turn bit ON
            }
        }
    }
}

// Remove number from window
void remove_number(ll x, vector<int> &bit_count, ll &current_or) {
    for (int i = 0; i < 31; i++) {
        if (x & (1LL << i)) {
            bit_count[i]--;
            if (bit_count[i] == 0) {
                current_or &= ~(1LL << i);  // turn bit OFF
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<int> bit_count(31, 0);
    ll current_or = 0;
    ll result = 0;

    // Only store current window of size k (circular)
    vector<ll> window(k);

    // First element
    window[0] = x;
    add_number(window[0], bit_count, current_or);

    // Generate rest of first window
    for (int i = 1; i < k; i++) {
        window[i] = (a * window[i - 1] + b) % c;
        add_number(window[i], bit_count, current_or);
    }

    result ^= current_or;

    // Slide window
    for (ll i = k; i < n; i++) {

        // Generate next value
        ll new_value = (a * window[(i - 1) % k] + b) % c;

        // Element leaving window
        ll old_value = window[i % k];

        remove_number(old_value, bit_count, current_or);

        // Replace with new value
        window[i % k] = new_value;
        add_number(new_value, bit_count, current_or);

        result ^= current_or;
    }

    cout << result << "\n";

    return 0;
}