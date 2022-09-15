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
    int l[n], r[n];

    bool cmp = 1;

    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        if(l[i] % 2 == 0) l[i]++;
        if(r[i] % 2 == 0) r[i]--;

        if(l[i] > r[i])
            cmp = 0;

        l[i] /= 2;
        r[i] /= 2;
    }

    if(cmp == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    bool dp[n][n];
    memset(dp, 0, sizeof(dp));

    ii p[n][n];

    for(int i = 0; i < n; i++) {
        if(l[i] == 0) {
            dp[i][i] = 1;
            p[i][i].first = -1;
            p[i][i].second = 1;
        }
    }

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i+len-1 < n; i++) {
            int j = i + len - 1;
            
            if(len-1 >= l[i] and len-1 <= r[i] and dp[i+1][j]) {
                dp[i][j] = 1;
                p[i][j].first = -1;
                p[i][j].second = 2 * (len-1) + 1;
            }
            else {
                for(int k = i; k < j; k++) {
                    if(dp[i][k] and dp[k+1][j]) {
                        dp[i][j] = 1;
                        p[i][j].first = k-i+1;
                    }
                }
            }
        }
    }

    if(dp[0][n-1] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    queue<ii> q;
    q.push(make_pair(0, n-1));

    int d[n];

    while(!q.empty()) {
        ii pos = q.front(); q.pop();
        int x = pos.first, y = pos.second;

        if(p[x][y].first == -1) {
            d[x] = p[x][y].second;
            if(x != y) q.push(make_pair(x+1, y));
        }
        else {
            int L = p[x][y].first;
            q.push(make_pair(x, x+L-1));
            q.push(make_pair(x+L, y));
        }
    }

    string ans = string(2 * n, '.');

    int ind = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(ans[i] == '.') {
            ans[i] = '(';
            ans[i + d[ind++]] = ')';
        }
    }

    cout << ans << "\n";
	
    return 0;
}


