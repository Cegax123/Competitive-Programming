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
        int n, k; cin >> n >> k;
        set<ii> a;

        vi pos[k+1];

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            pos[x].pb(i);
            a.insert({i, x});
        }

        for(int i = 1; i <= k; i++) {
            if(pos[i].empty()) {
                cout << 0 << " ";
                continue;
            }

            int L = a.begin()->first;
            int R = a.rbegin()->first;

            cout << 2 * (R-L+1) << " ";

            for(int p : pos[i]) a.erase({p, i});
        }

        cout << "\n";
    }

	
    return 0;
}


