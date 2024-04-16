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

const int maxn = 1e5+5;
int c[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string s, t; cin >> s >> t;

        s += '.';
        t += '#';

        set<int> sc;
        
        for(int i = 0; i <= n; i++) {
            c[i] = s[i] == t[i];
            if(i < n) sc.insert(s[i]);
        }

        vi v;
        
        for(int x : sc) v.pb(x);

        int p = v.size();

        ll ans = 0;

        for(int i = 0; i < (1 << p); i++) {
            int cnt = 0;
            ll currans = 0;
            sc.clear();

            for(int j = 0; j < p; j++) {
                if((i >> j)&1) {
                    cnt++;
                    sc.insert(v[j]);
                }
            }

            if(cnt > k) continue;

            ll curr = 0;
            for(int j = 0; j <= n; j++) {
                if(c[j] or sc.count(s[j])) {
                    curr++;
                }
                else {
                    currans += curr * (curr+1) / 2;
                    curr = 0;
                }
            }

            ans = max(ans, currans);
        }

        cout << ans << "\n";
    }

	
    return 0;
}


