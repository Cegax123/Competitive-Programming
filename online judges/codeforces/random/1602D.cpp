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

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	vi a(n+1), b(n+1);
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
		
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	
	b[0] = 0;
		
	int d[n+1][2];

	for(int i = 0; i <= n; i++)
		d[i][0] = d[i][1] = INF;
	
	d[n][0] = d[n][1] = 0;
	int ind = n;
	
	queue<int> q;
	q.push(n);

	int p[n+1][2];
	
	memset(p, -1, sizeof(p));
	p[n][0] = n;

	while(!q.empty()) {
		int v = q.front(); q.pop();
		int to = v - a[v];
		
		for(int i = ind; i >= to; i--) {
			if(d[i][1] == INF and d[i+b[i]][0] > d[v][0]+1) {
				d[i][1] = d[v][0]+1;
				d[i+b[i]][0] = d[i][1];
				
				p[i][1] = v;
				p[i+b[i]][0] = i;
				
				if(i+b[i]) q.push(i+b[i]);
			}
		}
		
		ind = min(ind, to);
	}  
	
	//for(int i = 0; i <= n; i++)
		//cout << p[i][0] << " " << p[i][1] << "\n";
	
	if(d[0][0] == INF) cout << "-1\n";
	else {
		int v = 0;
		vi ans;

		while(v != n) {
			ans.pb(v);
			//cout << v << endl;
			v = p[v][1];
			v = p[v][0];
		}
		
		reverse(all(ans));
		
		cout << ans.size() << "\n";
		for(auto x : ans)
			cout << x << " ";
		cout << "\n";
	}
		

	return 0;
}
