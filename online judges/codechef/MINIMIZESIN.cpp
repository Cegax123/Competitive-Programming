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

const int L = 180;

int norm(int x) {
    x %= L;
    if(x < 0) x += L;
    return min(x, L-x);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q; cin >> n >> q;
    ll a[n+1];

    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= L;
        if(a[i] < 0) a[i] += L;
    }
    
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int i, x; cin >> i >> x;
            a[i] = x;

            a[i] %= L;
            if(a[i] < 0) a[i] += L;
        }
        else {
            int l, r; cin >> l >> r;
            r = min(r, l+L);

            vii c;
            c.pb({0, l-1});

            for(int i = l; i <= r; i++) {
                c.pb({a[i]+c.back().first, i});
                c.back().first = norm(c.back().first);
            }

            sort(all(c));

            //for(auto e : c) {
                //cout << e.first << " " << e.second << "\n";
            //}
            //cout << endl;
            
            int ans = L;
            int ansL = -1, ansR = -1;

            for(int i = 0; i < (int) c.size(); i++) {
                int j = (i+1) % ((int) c.size());

                int diff = norm((c[i].first-c[j].first) * (c[i].second > c[j].second ? 1 : -1));

                //cout << i << " " << diff << endl;

                if(diff < ans) {
                    ans = diff;
                    ansL = min(c[i].second, c[j].second)+1;
                    ansR = max(c[i].second, c[j].second);
                }
            }
            //cout << ans << " ";
            cout << ansL << " " << ansR << "\n";

            //cout << endl;
        }
    }

    return 0;
}


