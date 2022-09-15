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

const int maxn = 2e5+5;

vector<int> parent, rk;

void make_set(int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap(a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            rk[a]++;
    }
}

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
    	int n, m; cin >> n >> m;

    	parent.clear(); rk.clear();
    	parent.resize(n); rk.resize(n);

    	for(int i = 0; i < n; i++)
    		make_set(i);

    	for(int i = 0; i < m; i++) {
    		int a, b; cin >> a >> b;
    		a--; b--;

    		a = find_set(a), b = find_set(b);

    		if(a != b) union_sets(a, b);
    	}

    	vi nodes[n];

    	for(int i = 0; i < n; i++) 
    		nodes[find_set(i)].pb(i);

    	vi d(n, INF);
    	
    	queue<int> q;
    		
    	for(int i : nodes[find_set(0)]) {
    		q.push(i);
    		d[i] = 0;
    	}

    	while(!q.empty()) {
    		int v = q.front(); q.pop();

    		if(v-1 >= 0 and d[v-1] == INF) {
    			for(int i : nodes[find_set(v-1)]) {
    				q.push(i);
    				d[i] = d[v]+1;
    			}
    		}

    		if(v+1 < n and d[v+1] == INF) {

    			for(int i : nodes[find_set(v+1)]) {
    				q.push(i);
    				d[i] = d[v]+1;
    			}
    		}
    	}

    	cout << d[n-1] << "\n";
    }
	
	
    return 0;
}
