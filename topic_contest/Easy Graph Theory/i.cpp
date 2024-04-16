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
    int n, m, v; cin >> n >> m >> v;

    int out = (v == 1 ? 2 : 1);

    if(m < n-1 or m > (n-1) * 1ll * (n-2) / 2 + 1) {
        cout << -1 << "\n";
        return 0;
    }

    vi nodes;
    nodes.pb(v);

    for(int i = 1; i <= n; i++) {
        if(i != out and i != v) nodes.pb(i);
    }

    cout << v << " " << out << "\n";
    m--;

    for(int L = 1; L <= n-1; L++) {
        for(int j = 0; j + L < n-1; j++) {
            cout << nodes[j] << " " << nodes[j+L] << "\n";
            m--;

            if(m == 0) break;
        }

        if(m == 0) break;
    }
	
    return 0;
}


