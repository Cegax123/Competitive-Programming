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
        int n, k, v; cin >> n >> k >> v;

        int x = 0;
        for(int i = 1; i <= n; i++) {
            x ^= i;
        }

        bool cmp = 0;
        if((k&1) and v == x) cmp = 1;
        if((k&1) == 0 and x == 0) cmp = 1;

        if(!cmp) {
            cout << "NO\n";
            continue;
        }

        bool vis[n+1];
        memset(vis, 0, sizeof(vis));

        int cnt = 0;

        vector<vi> p;
        vi lft;

        for(int i = 0; i <= n; i++) {
            if(vis[i]) continue;
            int j = v ^ i;

            if(j == i or j < 0 or j > n) {
                lft.pb(i);
                continue;
            }

            vis[i] = vis[j] = 1;
            p.pb({i, j});
            cnt++;
        }

        int x2 = 0;

        for(int e : lft) x2 ^= e;

        if(x2 == 0) {
            if(p.empty()) {
                cout << "NO\n";
                continue;
            }
            for(int e : lft)
                p[0].pb(e);
        }
        else {
            if(x2 != v) {
                cout << "NO\n";
                continue;
            }
            cnt++;
            p.pb(lft);
        }

        if(cnt % 2 != k % 2) {
            cout << "NO\n";
            continue;
        }

        if(cnt < k) {
            cout << "NO\n";
            continue;
        }


        while(cnt > k) {
            for(int e : p.back())
                p[0].pb(e);
            p.pop_back();

            for(int e : p.back())
                p[0].pb(e);
            p.pop_back();

            cnt -= 2;
        }

        cout << "YES\n";

        for(auto ve : p) {
            int has_zero = 0;
            int curr_x = 0;
            
            for(int e : ve) {
                if(e == 0) has_zero = 1;
                curr_x ^= e;
            }

            assert(curr_x == v);

            cout << ve.size()-has_zero << " ";


            for(int e : ve) {
                if(e) cout << e << " ";
            }
            cout << "\n";
        }
    }

	
    return 0;
}


