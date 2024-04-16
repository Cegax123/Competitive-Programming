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

const int maxn = 1e6 + 5;

int a[maxn];
int cnt[3 * maxn];

void solve(int l, int r) {
    if(l == r) {
        cnt[a[l]] = 1;
        return;
    }

    int m = (l+r) >> 1;

    solve(l, m);
    solve(m+1, r);

    vi L(1, a[m]), R(1, a[m+1]);

    for(int i = m-1; i >= l; i--) {
        int x = L.back() | a[i];
        if(x != L.back()) L.pb(x);
    }

    for(int i = m+2; i <= r; i++) {
        int x = R.back() | a[i];
        if(x != R.back()) R.pb(x);
    }

    for(int x : L) {
        for(int y : R) {
            cnt[x | y] = 1;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    solve(0, n-1);

    int ans = 0;
    for(int i = 0; i < 3 * maxn; i++)
        ans += cnt[i];
	
    cout << ans << "\n";
    return 0;
}


