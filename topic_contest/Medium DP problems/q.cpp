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
    int n, k, v; cin >> n >> k >> v;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    if(v % k == 0) {
        int sum = accumulate(a, a+n, 0);

        if(sum >= v) {
            cout << "YES\n";
            for(int i = 1; i < n; i++) {
                if((a[i] + k - 1) / k) 
                    cout << (a[i] + k - 1) / k << " " << i+1 << " " << 1 << "\n";
            }

            if(v/k) cout << v / k << " " << 1 << " " << 2 << "\n";
        }
        else cout << "NO\n";

        return 0;
    }

    bool all[n][k];
    int dp[n][k];

    memset(all, 0, sizeof(all));
    memset(dp, -1, sizeof(dp));

    all[0][0] = 0;
    dp[0][0] = 0;

    all[0][a[0]%k] = 1;
    dp[0][a[0]%k] = a[0];
	
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < k; j++) {
            if(dp[i-1][j] == -1) continue;
            int y = (j + a[i]) % k;

            if(dp[i][y] < dp[i-1][j] + a[i]) {
                dp[i][y] = dp[i-1][j] + a[i];
                all[i][y] = 1;
            }

            if(dp[i][j] < dp[i-1][j] + (a[i] / k) * k) {
                dp[i][j] = dp[i-1][j] + (a[i] / k) * k;
                all[i][j] = 0;
            }
        }
    }

    int lft = accumulate(a, a+n, 0) - v;
    
    if(lft < 0 or dp[n-1][v%k] == -1) {
        cout << "NO\n";
        return 0;
    }

    vector<bool> marked(n, 0);

    int curr = v % k;

    for(int i = n-1; i >= 0; i--) {
        if(all[i][curr]) {
            marked[i] = 1;

            curr -= a[i];
            curr %= k;
            if(curr < 0) curr += k;
        }
    }

    int target = -1, off = -1;

    vector<pair<int, ii>> ord;

    for(int i = 0; i < n; i++) {
        if(target != -1) {
            if(marked[i]) {
                ord.pb({(a[i]+k-1)/k, {i+1, target+1}});
                a[target] += a[i];
            }
        }

        if(target == -1 and marked[i]) target = i;

        if(off != -1) {
            if(!marked[i]) {
                ord.pb({(a[i] + k - 1) / k, {i+1, off+1}});
                a[off] += a[i];
            }
        }

        if(off == -1 and !marked[i]) off = i;
    }

    if(off != -1) {
        ord.pb({a[off]/k, {off+1, target+1}});
        a[target] += (a[off]/k) * k;
    }

    if(a[target] >= v) {
        cout << "YES\n";

        ord.pb({(a[target]-v)/k, {target+1, (target == 0 ? 2 : 1)}});

        for(auto e : ord) {
            if(e.first == 0) continue;
            cout << e.first << " " << e.second.first << " " << e.second.second << "\n";
        }
    }
    else {
        cout << "NO\n";
    }

    return 0;
}


