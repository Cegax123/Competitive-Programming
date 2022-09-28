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
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    if(m <= 100) {
        vector<vi> son(1);
        vi h(1, 0);

        vector<vector<ll>> val; 
        vector<ll> sum(1, 0);
        val.pb(a);

        int sz = 1;

        queue<int> q;
        q.push(0);

        for(int i = 0; i < n; i++)
            sum[0] += a[i];

        for(int i = 0; i < m; i++) {
            queue<int> curr;

            while(not q.empty()) {
                int x = q.front(); q.pop();

                int nl = -1, nr = -1;
                for(ll y : val[x]) {
                    if(y % b[i] == 0) {
                        if(nl == -1) {
                            nl = sz++;
                            val.pb(vector<ll>(0));
                            h.pb(h[x]+1);
                            curr.push(nl);
                            son.pb(vi());
                            sum.pb(0);
                        }
                        val[nl].pb(y);
                        sum[nl] += y;
                    }
                    else {
                        if(nr == -1) {
                            nr = sz++;
                            val.pb(vector<ll>(0));
                            h.pb(h[x]+1);
                            curr.push(nr);
                            son.pb(vi());
                            sum.pb(0);
                        }
                        val[nr].pb(y);
                        sum[nr] += y;
                    }
                }

                if(nl != -1) son[x].pb(nl);
                if(nr != -1) son[x].pb(nr);
            }


            q = curr;

        }

        ll ans[sz];

        for(int i = sz-1; i >= 0; i--) {
            if(h[i] == m) {
                ans[i] = sum[i];
                continue;
            }
            if(h[i] % 2 == 0) {
                if(son[i].size() == 2) {
                    ans[i] = min(ans[son[i][0]], ans[son[i][1]]);
                }
                else {
                    ans[i] = min(ans[son[i][0]], 0ll);
                }
            }
            else {
                if(son[i].size() == 2) {
                    ans[i] = max(ans[son[i][0]], ans[son[i][1]]);
                }
                else {
                    ans[i] = max(ans[son[i][0]], 0ll);
                }
            }
        }

        cout << ans[0] << endl;
    }

    else cout << 0 << "\n";

    return 0;
}


