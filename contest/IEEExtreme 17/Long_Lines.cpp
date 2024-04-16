#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, h0, a, c, q; cin >> n >> h0 >> a >> c >> q;
    int h[n];

    h[0] = h0;

    for(int i = 1; i < n; i++) {
        h[i] = (a * 1ll * h[i-1] + c) % q;
    }

    stack<int> st;
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ans += st.size();

        while(!st.empty() and st.top() <= h[i]) {
            st.pop();
        }

        st.push(h[i]);
    }
    
    cout << ans << "\n";

    return 0;
}
