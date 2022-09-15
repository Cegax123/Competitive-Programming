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
    int n, q; cin >> n >> q;
    int p[n];
    int out[n];
    memset(out, 0, sizeof(out));

    for(int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        out[p[i]]++;
    }

    while(q--) {
        int m; cin >> m;
        set<int> s;
        int ans = m;

        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            x--;

            ans += out[x];
            s.insert(x);
        }
        
        for(int x : s) {
            if(x == 0) continue;
            else if(s.count(p[x])) ans -= 2;
        }

        cout << ans << "\n";
    }
	
    return 0;
}


