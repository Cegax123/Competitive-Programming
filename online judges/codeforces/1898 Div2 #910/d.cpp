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

int a[maxn], b[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        ll ans = 0;

        for(int i = 0; i < n; i++) ans += abs(a[i]-b[i]);

        vector<pair<int, int>> p(n);

        for(int i = 0; i < n; i++) p[i] = {min(a[i], b[i]), max(a[i], b[i])};

        sort(p.begin(), p.end());

        int L = p.back().first;

        ll curr = ans;

        for(int i = 0; i < n; i++) {
            if(p[i].second < L) ans = max(ans, curr + 2 * (L-p[i].second));
        }

        cout << ans << "\n";
    }

	
    return 0;
}


