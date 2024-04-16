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
const ll INF = (ll) 1e18;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int a[n+1];

    for(int i = 1; i <= n; i++) cin >> a[i];

    set<pair<ll, int>> s;

    ll p[n+1];
    p[0] = 0;

    int r[n+1];
    r[0] = 0;

    s.insert({0, 0});

    int maxr = 0;
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i];

        pair<ll, int> curr = {p[i], n+1};
        
        s.insert(curr);

        auto it = s.find(curr);

        if(it == s.begin()) {
            r[i] = -i;
        }
        else {
            it = prev(it);
            r[i] = (*it).second;
        }

        ans = max(ans, r[i] + i);

        r[i] = max(r[i], r[i-1]-1);
        maxr = max(maxr, r[i]);

        s.erase(curr);

        s.insert({p[i], r[i]});
        it = s.find({p[i], r[i]});

        while(next(it) != s.end()) {
            auto nxt = next(it);

            if((*nxt).second <= r[i]) s.erase(nxt);
            else break;
        }
    }

    cout << ans << "\n";
	
    return 0;
}


