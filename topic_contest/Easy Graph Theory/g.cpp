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
    int n, m; cin >> n >> m;
    vector<bool> banned(n, 0);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;

        banned[u] = banned[v] = 1;
    }

    int u = -1;
    for(int i = 0; i < n; i++) {
        if(!banned[i]) u = i;
    }

    cout << n-1 << "\n";
    for(int i = 0; i < n; i++) {
        if(i == u) continue;
        cout << u+1 << " " << i+1 << "\n";
    }
	
    return 0;
}

