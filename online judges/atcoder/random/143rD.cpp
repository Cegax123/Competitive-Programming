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

const int N = 4e5+5;
vi adj[N] ;
vii ans;
int vis[N], dp[N], deep[N];
int bridge = 0;
int src;

void dfs(int v, int p){
	vis[v] = 1;

	if(v!=src) deep[v] = deep[p]+1;
	else deep[v] = 0;

	int sum,up,dow;
	sum = up = dow = 0;
	for(auto to:adj[v]){
		if(to==p)continue;
		if(!vis[to]){
			dfs(to,v);
			sum += dp[to];
		}
		else {
			if(deep[to]<deep[v]) up++;
			else dow++;
		}
	}
	dp[v]  = sum + up - dow;
	if(v!=src and dp[v]==0) bridge++;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	int k = n/2;

	for(int i = 0; i < k; i++) {
		adj[i].pb(i+k);
		adj[i+k].pb(i);
	}

	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		b += k;

		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			src = i;
			dfs(i, -1);
		}
	}
	cout << bridge << endl;
}

