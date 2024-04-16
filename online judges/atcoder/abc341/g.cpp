#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    ll p[n+1];
    p[0] = 0;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a, a+n);
    for(int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i-1];
    }

    vector<pair<ll, int>> st;
    st.push_back({p[0], 0});

    cout << setprecision(12) << fixed;

    double ans[n];

    for(int i = 1; i <= n; i++) {
        while((int) st.size() >= 2) {
            int k = st.size();
            ll dx = st[k-1].first - st[k-2].first;
            ll dy = st[k-1].second - st[k-2].second;

            ll cx = p[i] - st[k-1].first;
            ll cy = i - st[k-1].second;

            if(cx * dy < dx * cy) {
                st.pop_back();
                continue;
            }
            else break;
        }

        ll dx = p[i] - st.back().first, dy = i - st.back().second;
        ans[n-i] = (double) dx / dy;

        st.push_back({p[i], i});
    }

    for(int i = 0; i < n; i++) cout << ans[i] << "\n";
	
    return 0;
}


