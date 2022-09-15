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
 
const int SUML = 1e6 + 5;
const int E = 26;
 
int n, k;
int nodes;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
int id[SUML];
 
const int maxn = 1e5+5;
 
vi tree[maxn];
int h[maxn];
vector<bool> present(maxn, true);
 
void insert(const string& s, int ind){
	int pos = 0;
	for(int i = 0; i < (int) s.size(); i++){
		int nxt = s[i] - 'a';
		if(trie[pos][nxt] == 0){
			trie[pos][nxt] = nodes++;
		}
		pos = trie[pos][nxt];
	}
	term[pos]++;
 
    id[pos] = ind;
}
 
void build(int src=0){
	queue<int> Q;
	Q.emplace(src);
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
 
		if(term[suf[u]]) super[u] = suf[u];
		else super[u] = super[suf[u]];
 
 
        if(term[u]) {
            int a = id[u];
            int b = id[super[u]];
 
            h[a] = h[b]+1;
 
            tree[a].pb(b);
            tree[b].pb(a);
        }
 
		// cout << u << endl;
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
 
vi a;
int sz[maxn];
int ps[maxn];
 
void dfs(int v, int p = -1) {
    sz[v] = 1;
    a.pb(v);
    ps[v] = a.size()-1;
 
    for(int to : tree[v]) {
        if(to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
    }
}
 
int lazy[4*maxn];
 
void push(int v) {
    lazy[v*2] += lazy[v];
    lazy[v*2+1] += lazy[v];
 
    lazy[v] = 0;
}
 
void update(int v, int tl, int tr, int l, int r, int x) {
    if(l > tr or r < tl) 
        return;
    if(tl == l and tr == r) {
        lazy[v] += x;
    }
    else {
        push(v);
        int tm = (tl+tr) >> 1;
        update(v*2, tl, tm, l, min(r, tm), x);
        update(v*2+1, tm+1, tr, max(tm+1, l), r, x);
    }
}
 
int query(int v, int tl, int tr, int pos) {
    if(tl == tr)
        return lazy[v];
    else {
        push(v);
        int tm = (tl+tr) >> 1;
 
        if(pos <= tm) return query(v*2, tl, tm, pos);
        else return query(v*2+1, tm+1, tr, pos);
    }
}
 
ll solve(const string& s) {
    int pos = 0;
    ll ans = 0;
    for(int i = 1; i < (int) s.size(); i++) {
        int nxt = s[i]-'a';
        pos = go[pos][nxt];
 
        int sup = super[pos];
        if(term[pos]) sup = pos;
 
        ans += h[id[sup]]+query(1, 0, k, ps[id[sup]]);
    }
 
    return ans;
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    nodes = 1;
 
    cin >> n >> k;
 
    for(int i = 0; i < k; i++) {
        string s; cin >> s;
        insert(s, i+1);
    }
 
    build();
    dfs(0);
 
    while(n--) {
        string q; cin >> q;
 
        if(q[0] == '?') {
            cout << solve(q) << "\n";
        }
        else {
            int num = 0;
 
            for(int i = 1; i < (int) q.size(); i++) {
                num = (10 * num) + q[i]-'0';
            }
 
            if((q[0] == '+' and present[num]) or (q[0] == '-' and present[num] == false)) continue;
            int x = 1;
 
            if(q[0] == '-') x = -1;
 
            update(1, 0, k, ps[num], ps[num]+sz[num]-1, x);
 
            present[num] = 1 - present[num];
        }
    }
 
	return 0;
}
