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
    int n, m, p; cin >> n >> m >> p;

    vii adj[n+1];

    for(int i = 0; i < m; i++) {
        int l, r, w; cin >> l >> r >> w;
        adj[l-1].pb({r, w});
        adj[r].pb({l-1, (p-w)%p});
    }
    
    int s[n+1];
    memset(s, 0, sizeof(s));

    bool vis[n+1];
    memset(vis, 0, sizeof(vis));
    
    for(int i = 0; i <= n; i++) {
    	if(vis[i]) continue;
    	if(i == 0) s[i] = 0;
    	else s[i] = s[i-1];
    	
    	queue<int> q;
    	q.push(i);
    	while(!q.empty()) {
    		int v = q.front(); q.pop();
	    	for(auto e : adj[v]) {
	    		int to = e.first, w = e.second;
	    		if(vis[to]) continue;
	    		q.push(to);
	    		s[to] = (s[v] + w) % p;
	    		vis[to] = 1;
	    	}
    	}
    }
    
    bool flag = true;
    for(int i = 0; i <= n; i++) {
    	for(auto e : adj[i]) {
    		int to = e.first, w = e.second;
    		if((s[i] + w) % p != s[to]) flag = false;
    	}
    }
    
    if(!flag) {
    	cout << "None\n";
    	return 0;
    }

	for(int i = 1; i <= n; i++) {
		int x = (s[i]-s[i-1]) % p;
		x = (x+p)%p;
		
		cout << x << " ";
	}

	
    return 0;
}



