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
 
const int maxn = 200 + 5;
const int SUML = 200 + 5;
const int E = 26;
const ll INF = (ll) 1e18;
 
int n;
int nodes;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int go[SUML][E];
 
ll l, a[maxn];
int val[maxn];
int b[maxn];
 
void insert(const string& s, int x){
	int pos = 0;
	for(int i = 0; i < (int) s.size(); i++){
		int nxt = s[i] - 'a';
		if(trie[pos][nxt] == 0){
			trie[pos][nxt] = nodes++;
		}
		pos = trie[pos][nxt];
	}
	val[pos] += x;
	term[pos]++;
}
 
void BFS(int src){
	queue<int> Q;
	Q.emplace(src);
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
 
		for(int c = 0; c < E; c++){
			if(trie[u][c]){
				int v = trie[u][c];
				Q.emplace(v);
				
				go[u][c] = trie[u][c];
				suf[v] = u == 0 ? 0 : go[suf[u]][c];
			}
			else{
				go[u][c] = u == 0 ? 0 : go[suf[u]][c];
			}
		}
	}
}
 
typedef vector<vector<ll>> Mat;
 
Mat mul(const Mat& A, const Mat& B) {
	int a = A.size(), b = A[0].size(), c = B[0].size();
	Mat res(a, vector<ll>(c, -INF));
 
	for(int i = 0; i < a; i++) {
		for(int j = 0; j < b; j++) {
			for(int k = 0; k < c; k++) {
				res[i][k] = max(res[i][k], A[i][j] + B[j][k]);
			}
		}
	}
 
	return res;
}
 
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	nodes = 1;
 
	cin >> n >> l;
 
	for(int i = 0; i < n; i++)
		cin >> a[i];
 
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		insert(s, a[i]);
	}
 
	BFS(0);
 
	for(int i = 0; i < nodes; i++) {
		int tmp = i;
 
		while(tmp) {
			b[i] += val[tmp]; 
			tmp = suf[tmp];
		}
	}
 
	Mat A(nodes, vector<ll>(nodes, -INF)), B(nodes, vector<ll>(1, -INF));
	B[0][0] = 0;
 
	for(int i = 0; i < nodes; i++) {
		for(int j = 0; j < E; j++) {
			int nxt = go[i][j];
			if(A[nxt][i] == -INF) A[nxt][i] = 0;
			A[nxt][i] += b[nxt];
		}
	}
 
	while(l) {
		if(l&1ll) {
			B = mul(A, B);
		}
 
		l >>= 1;
		A = mul(A, A);
	}
 
	ll ans = 0;
	for(int i = 0; i < nodes; i++) 
		ans = max(ans, B[i][0]);
 
	cout << ans << "\n";
 
	return 0;
}
