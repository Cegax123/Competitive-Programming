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
    vector<vi> adj(n+1);
    vi in(n+1, 0);

    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);

        in[y]++;
    }

    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) q.push(i);
    }

    int ans[n+1];
    bool cmp = 1;
    int ind = 1;

    while(!q.empty()) {
        if((int) q.size() > 1) cmp = 0;
        int v = q.front(); q.pop();

        ans[v] = ind++;

        for(int to : adj[v]) {
            in[to]--;
            if(in[to] == 0) q.push(to);
        }
    }

    if(cmp == 0) cout << "No\n";
    else {
        cout << "Yes\n";

        for(int i = 1; i <= n; i++)
            cout << ans[i] << " ";
    }
	
    return 0;
}


