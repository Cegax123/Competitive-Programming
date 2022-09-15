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
        int n, m; cin >> n >> m;

        int a[n];
        map<int, int> freq;
        set<ii> banned;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
            
            banned.insert({a[i], a[i]});
        }

        map<int, vi> gr;

        for(auto& e : freq) 
            gr[e.second].pb(e.first);

        for(auto& e : gr) 
            sort(e.second.rbegin(), e.second.rend());

        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            banned.insert({u, v});
            banned.insert({v, u});
        }

        ll ans = 0;

        for(auto& elem : freq) {
            int x = elem.first;
            int fx = elem.second;

            for(auto& e : gr) {
                int fe = e.first;
                
                if(fe > fx) continue;

                for(int& el : e.second) {
                    if(!banned.count({x, el})) {
                        ans = max(ans, (ll) (fx + fe) * (x + el));
                        break;
                    }
                }
            }
        }

        cout << ans << "\n";
    }
	
	
	return 0;
}

