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

class Edge{
public:
	int u,v;
	ll cap,flow = 0;
	Edge(int _u,int _v,long long _cap){
		u=_u,v=_v,cap=_cap;
	}
};
class Dinic{
public:
	const ll inf = 1e18;
	vector<Edge> e;
	vector<vector<int>> adj;
	vector<int> d,ptr;
	int n,m=0,s,t;
	queue<int> q;
	Dinic(int _n, int _s, int _t){
		n=_n,s=_s,t=_t;
		adj.resize(n);
		d.resize(n);
		ptr.resize(n);
	}
	void add_edge(int u, int v, ll cap){
		e.pb(Edge(u, v, cap));
		e.pb(Edge(v, u, 0));
		adj[u].pb(m++);
		adj[v].pb(m++);
	}

	void add_bidirectional_edge(int u,int v,ll cap){
        e.pb(Edge(u,v,cap));
        e.pb(Edge(v,u,cap));
        adj[u].pb(m++);
        adj[v].pb(m++);
	}

	bool bfs(){
		while(!q.empty()){
			int now = q.front();
			q.pop();
			for(int id:adj[now]){
				if(e[id].cap - e[id].flow <= 0) continue;
				if(d[e[id].v] != -1) continue;
				d[e[id].v] = d[now] + 1;
				q.push(e[id].v);
			}
		}
		return d[t] != -1;
	}

	ll dfs(int now,ll flow){
		if(now==t || flow == 0) return flow;
		for(;ptr[now] < (int) adj[now].size(); ptr[now]++){
			int id = adj[now][ptr[now]];
			if(d[e[id].v] != d[now] + 1 || e[id].cap - e[id].flow < 1) continue;
			ll res = min(flow, e[id].cap - e[id].flow);
            if(int new_flow = dfs(e[id].v,res)){
                e[id].flow += new_flow;
                e[id ^ 1].flow -= new_flow;
                return new_flow;
			}
		}
        return 0;
	}

	ll flow(){
		ll flow = 0;
		while(true){//V iteraciones
			fill(d.begin(), d.end(), -1);
			d[s] = 0;
			q.push(s);
			if(!bfs()) break;
			fill(ptr.begin(),ptr.end(),0);
			while(ll curr_flow = dfs(s,inf)){//Complejidad V*E

				flow += curr_flow;
			}
		}
		return flow;
	}
    void vdfs(int now,vector<bool> &vis){
        vis[now] = true;
        for(int id:adj[now]){
            if(!vis[e[id].v] && e[id].cap-e[id].flow>0) vdfs(e[id].v,vis);
        }
	}
	void minCut(vector<bool> &cut){
        cut.assign(n,false);
        vdfs(s,cut);
	}
};
const int maxv = 40005;
vector<vi> adj;
int a[maxv];

const int maxn = 500000 + 5;
int lp[maxn];
vi primes;
int id[maxn], col[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2; i < maxn; i++) {
		if(lp[i] == 0) {
			lp[i] = i;
			primes.pb(i);
		}

		for(int j = 0; j < (int) primes.size() and i * primes[j] < maxn; j++) {
			if(primes[j] > lp[i]) continue;
			lp[i * primes[j]] = primes[j];
		}
	}

    int t; cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		int n; cin >> n;
		adj.resize(n);

		Dinic dinic(n+2, n, n+1);

		for(int i = 1; i <= n; i++) {
			cin >> a[i-1];
			id[a[i-1]] = i;
		}

		for(int i = 0; i < n; i++) {
			int x = a[i];

			while(x != 1) {
				int d = lp[x];
				while(x % d == 0) x /= d;

				int to = a[i] / d;
				if(id[to]) {
					adj[id[a[i]]-1].pb(id[to]-1);
					adj[id[to]-1].pb(id[a[i]]-1);
				}
			}
		}

		for(int i = 0; i < n; i++) {
			if(col[i] == 0) {
				queue<int> q;
				q.push(i);
				col[i] = 1;

				while(!q.empty()) {
					int v = q.front(); q.pop();

					for(int to : adj[v]) {
						if(col[to] == 0) {
							q.push(to);
							col[to] = 3 - col[v];
						}
					}
				}
			}
		}

		for(int i = 0; i < n; i++) {
			if(col[i] == 1) {
				for(int to : adj[i]) {

					dinic.add_edge(i, to, 1);
					//cout << i << " " << to << " " << col[i] << " " << col[to] << endl;
				}
			}
		}

		for(int i = 0; i < n; i++) {
			if(col[i] == 1) dinic.add_edge(n, i, 1);
			else dinic.add_edge(i, n+1, 1);
		}

		ll q = dinic.flow();
		cout << "Case " << tt << ": ";
		cout << n-q << "\n";


		for(int i = 0; i < n; i++) {
			col[i] = 0;
			id[a[i]] = 0;
		}

		adj.clear();
    }

	
    return 0;
}


