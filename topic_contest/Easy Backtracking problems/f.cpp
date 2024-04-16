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

const int maxn = 12;

vi a(1, 1);
int n, m;
int curr, ans=0;

vector<tuple<int, int, int>> queries[maxn];

void solve(int pos=1) {
    if(pos == n+1) {
        ans = max(ans, curr);
        return;
    }
    
    for(int i = a.back(); i <= m; i++) {
        a.pb(i);
        int added = 0;
        for(auto e : queries[pos]) {
            if(a[pos] - a[get<0>(e)] == get<1>(e)) {
                added += get<2>(e);
            }
        }
        curr += added;

        solve(pos+1);

        curr -= added;
        a.pop_back();
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q; cin >> n >> m >> q;

    for(int i = 0; i < q; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        queries[b].pb({a, c, d});
    }

    solve();

    cout << ans << "\n";
	
    return 0;
}


