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
const int maxp = 7;

int a[maxn];
ll dp[maxn][1 << maxp];
int s[maxp][maxn];
int order[maxn];
set<ii> vs[maxp];

bool blocked[maxp];
bool banned[maxn];
int choosen[maxp][maxp];

ll back_ans;
int n, p, k;

void backtrack(int l, int pos = 0, ll sum = 0) {
    if(pos == p) {
        back_ans = max(back_ans, sum);
        return;
    }

    if(blocked[pos]) {
        backtrack(l, pos+1, sum);
        return;
    }

    for(int j = 0; j < l; j++) {
        int x = choosen[pos][j];

        if(!banned[x]) {
            banned[x] = 1;

            backtrack(l, pos+1, sum + s[pos][x]);

            banned[x] = 0;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> p >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < p; j++) {
            cin >> s[j][i];
            vs[j].insert({s[j][i], i});
        }
    }

    iota(order + 1, order + n + 1, 1);
    sort(order + 1, order + n + 1, [](int x, int y) {
            return a[x] > a[y];
            });

    for(int i = 0; i < n; i++) 
        for(int mask = 0; mask < (1 << p); mask++)
            dp[i][mask] = (ll) -1e18;

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int mask = 0; mask < (1 << p); mask++) {
            dp[i][mask] = dp[i-1][mask] + a[order[i]];

            for(int j = 0; j < p; j++) {
                if(((mask >> j)&1) == 0) continue;

                dp[i][mask] = max(dp[i][mask], dp[i-1][mask ^ (1 << j)] + s[j][order[i]]);
            }
        }
    }

    for(int i = 1; i < k; i++) {
        for(int j = 0; j < p; j++) {
            vs[j].erase({s[j][order[i]], order[i]});
        }
    }

    ll ans = 0;

    for(int i = k; i <= k + p; i++) {
        int lft = i - k;

        for(int j = 0; j < p; j++) {
            vs[j].erase({s[j][order[i]], order[i]});
        }

        for(int mask = 0; mask < (1 << p); mask++) {
            memset(blocked, 0, sizeof(blocked));

            int cnt = __builtin_popcount(mask);
            if(lft != cnt) continue;

            int curr = p - cnt;

            for(int j = 0; j < p; j++) {
                if((mask >> j)&1) {
                    blocked[j] = 1;
                    continue;
                }

                auto it = vs[j].end();
                for(int t = 0; t < curr; t++) {
                    it = prev(it);
                    choosen[j][t] = it->second;
                }
            }

            back_ans = 0;
            backtrack(curr);

            ans = max(ans, dp[i][mask] + back_ans);
        }
    }

    cout << ans << "\n";

    return 0;
}


