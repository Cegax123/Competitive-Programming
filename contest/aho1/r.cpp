// SOLVED

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

const int maxn = 70;
// const int L = 19;
const int L = 19;
const int SUML = maxn * L + 5;
const int E = 10;

ll k, n;

int nodes;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
bool fin[SUML];

vi get_vec(ll x) {
    vi ans;
    for(int i = 0; i < L; i++) {
        ans.pb(x%10ll);
        x /= 10ll;
    }

    reverse(all(ans));

    return ans;
}

void insert(string s){
	int pos = 0;
	for(int i = 0; i < (int) s.size(); i++){
        int nxt = s[i]-'0';
		if(trie[pos][nxt] == 0){
			trie[pos][nxt] = nodes++;
		}
		pos = trie[pos][nxt];
	}
	term[pos]++;
}

void build(int src=0){
	queue<int> Q;
	Q.emplace(src);
	while(!Q.empty()){
		int u = Q.front(); Q.pop();

		if(term[suf[u]]) super[u] = suf[u];
		else super[u] = super[suf[u]];

        if(term[u] or super[u]) fin[u] = true;

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

vi num;
ll DP[L][SUML][2];

ll call(int pos, int q, bool f) {
    if(pos == (int) num.size()) {
        return fin[q];
    }

    if(DP[pos][q][f] != -1) 
        return DP[pos][q][f];

    int LMT = 9;
    if(f == 0) LMT = num[pos];

    if(fin[q]) {
        ll ans;
        if(f) {
            ans = 1;

            for(int i = pos; i < L; i++)
                ans *= 10ll;
        }
        else {
            ans = 0;

            for(int i = pos; i < L; i++) 
                ans = (10ll * ans) + (ll) num[i];

            ans++;
        }

        return DP[pos][q][f] = ans;
    }

    ll res = 0;

    for(int dgt = 0; dgt <= LMT; dgt++) {
        int nf = f;
        int n_st = go[q][dgt];
        if(f == 0 and dgt < LMT) nf = 1;
        
        res += call(pos+1, n_st, nf);
    }

    return DP[pos][q][f] = res;
}

ll solve(ll x) {
    if(x == 0) return 0;
    num.clear(); num = get_vec(x);

    memset(DP, -1, sizeof(DP));
    return call(0, 0, 0);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    nodes = 1;

    ll l, r; cin >> l >> r >> k >> n;

    for(int i = 0; i < n; i++) {
        string x; cin >> x;
        insert(x);
    }

    build();

    ll add = solve(l-1);
    k += add;

    l = 1;

    while(l < r) {
        ll m = (l+r)/2ll;

        if(solve(m) >= k) r = m;
        else l = m+1;
    }

    if(solve(l) == k) cout << l << "\n";
    else cout << "no such number\n";

	return 0;
}
