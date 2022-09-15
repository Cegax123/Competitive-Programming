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

const int maxn = 1e5 + 5;
const int B = 375;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    ll a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int t = 0;
    bool isHeavy[m];
    vi s[m], idx;

    int pos[m];
    bool comp[B][n];
    memset(comp, 0, sizeof(comp));

    for(int i = 0; i < m; i++) {
        int k; cin >> k;

        if(k < B) isHeavy[i] = 0;
        else {
            isHeavy[i] = 1;
            pos[i] = idx.size();
            idx.pb(i);
            t++;
        }


        for(int j = 0; j < k; j++) {
            int x; cin >> x; 
            x--;
            s[i].pb(x);
        }
    }

    ll sum[B];
    ll add[B];

    memset(sum, 0, sizeof(sum));
    memset(add, 0, sizeof(add));

    for(int i = 0; i < t; i++) {
        for(int x : s[idx[i]]) {
            comp[i][x] = 1;
            sum[i] += a[x];
        }
    }

    int cnt[m][B];
    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < m; i++) {
        for(int x : s[i]) {
            for(int j = 0; j < t; j++) {
                cnt[i][j] += comp[j][x];
            }
        }
    }

    while(q--) {
        char op; cin >> op;

        if(op == '?') {
            int k; cin >> k;
            k--;

            ll ans = 0;

            if(!isHeavy[k]) {
                for(int x : s[k])
                    ans += a[x];

                for(int i = 0; i < t; i++)
                    ans += add[i] * cnt[k][i];
            }
            else {
                int id = pos[k];
                ans = (ll) sum[id] + add[id] * s[k].size();
            }

            cout << ans << endl;
        }

        else {
            int k; cin >> k;
            k--;
            ll d; cin >> d;

            if(!isHeavy[k]) {
                for(int x : s[k]) 
                    a[x] += d;

                for(int i = 0; i < t; i++) 
                    sum[i] += (ll) d * cnt[k][i];
            }
            else {
                int id = pos[k];

                add[id] += d;
                for(int i = 0; i < t; i++) {
                    if(id == i) continue;
                    sum[i] += (ll) d * cnt[k][i];
                }
            }
        }
    }
	
    return 0;
}


