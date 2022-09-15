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
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vii p(n);

        for(int i = 0; i < n; i++)
            cin >> p[i].first;

        for(int i = 0; i < n; i++)
            cin >> p[i].second;

        p.pb({1, 1});

        sort(all(p));
        ll ans = 0;

        for(int i = 0; i < (int) p.size()-1; i++) {
            if(p[i] == p[i+1]) continue;

            int x1 = p[i].first-p[i].second+1, x2 = p[i+1].first - p[i+1].second + 1;
            int g1 = (x1+1) >> 1, g2 = (x2+1) >> 1;

            if(g1 != g2) ans += g2-g1;
            else {
                if(p[i+1].first-p[i].first == p[i+1].second - p[i].second and (x1&1)) {
                    ans += p[i+1].first-p[i].first;
                }
            }
        }

        cout << ans << "\n";
    }
	
	
	return 0;
}

