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

const int maxn = 2e5 + 5;

int a[maxn];
ll s[maxn];
double p[maxn];
double inv[maxn];

double C(int i, int j) {
    double ans = p[j] - (i == 0 ? 0.0 : p[i-1]);
    ans -= (inv[j] - (i == 0 ? 0.0 : inv[i-1])) * (i == 0 ? 0 : s[i-1]);
    return ans;
}

vector<double> dp, dp_bef;

void solve(int l, int r, int optl, int optr) {
    if(l > r) return;

    int mi = (l+r) >> 1;
    double bestAns = (ll) 1e18;
    int opt = -1;

    for(int k = optl; k <= min(mi, optr); k++) {
        double currAns = (k == 0 ? 0.0 : dp_bef[k-1]) + C(k, mi);
        if(currAns < bestAns) {
            bestAns = currAns;
            opt = k;
        }
    }

    dp[mi] = bestAns;

    solve(l, mi-1, optl, opt);
    solve(mi+1, r, opt, optr);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k; cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];

        inv[i] = (double) 1.0 / a[i];
        if(i) inv[i] += inv[i-1];
        
        s[i] = a[i];
        if(i) s[i] += s[i-1];
    }

    for(int i = 0; i < n; i++) {
        p[i] = (double) s[i] / a[i];
        if(i) p[i] += p[i-1];
    }

    dp.resize(n); dp_bef.resize(n);

    for(int i = 0; i < n; i++) {
        dp[i] = C(0, i);
    }

    for(int i = 1; i < k; i++) {
        swap(dp_bef, dp);
        solve(0, n-1, 0, n-1);
    }

    cout << setprecision(12) << fixed;
    cout << dp[n-1] << "\n";
	
    return 0;
}


