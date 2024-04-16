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

ii a[maxn], tmp[maxn];
int ans[maxn];

void solve(int l, int r) {
    if(l == r) {
        ans[l] = -1;
        return;
    }

    int m = (l+r) >> 1;
    solve(l, m);
    solve(m+1, r);

    int ind = m+1;
    int furthest = m;

    for(int i = l; i <= m; i++) {
        while(ind <= r and a[ind].first < a[i].first) {
            furthest = max(furthest, a[ind].second);
            ind++;
        }

        if(furthest > m) ans[a[i].second] = max(ans[a[i].second], furthest - a[i].second - 1);
    }

    merge(a+l, a+m+1, a+m+1, a+r+1, tmp+l);

    for(int i = l; i <= r; i++)
        a[i] = tmp[i];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }

    solve(0, n-1);

    for(int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
	
    return 0;
}


