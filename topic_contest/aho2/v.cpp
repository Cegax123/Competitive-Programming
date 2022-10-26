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

const int SUML = 2e5 + 5;
const int E = 26;

int n;
int nodes = 1;
int suf[SUML];
int term[SUML];
int super[SUML];
int go[SUML][E];
int val[SUML];
int h[SUML];

void insert(const string& s) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = s[i]-'a';
        if(go[pos][nxt] == 0) {
            go[pos][nxt] = nodes++;
            h[go[pos][nxt]] = h[pos]+1;
        }
        pos = go[pos][nxt];
    }
    term[pos]++;
}

void build(int src=0) {
    queue<int> Q;
    Q.emplace(src);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();

        if(term[suf[u]]) super[u] = suf[u];
        else super[u] = super[suf[u]];

        if(term[u]) val[u] += term[u];
        val[u] += val[suf[u]];

        for(int c = 0; c < E; c++) {
            if(go[u][c]) {
                int v = go[u][c];
                Q.emplace(v);

                suf[v] = u == 0 ? 0 : go[suf[u]][c];
            }
            else {
                go[u][c] = u == 0 ? 0 : go[suf[u]][c];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	string t; cin >> t;
    int k = t.size();

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        insert(s);
    }
	
    build();

    int st[k+1];

    for(int i = 0; i < k; i++) {
        int nxt = t[i]-'a';
        if(i == 0) st[i] = go[0][nxt];
        else st[i] = go[st[i-1]][nxt];
    }

    ll ans = 0;

    for(int i = 0; i < k; i++) {
        int tmp = term[st[i]] ? st[i] : super[st[i]];

        while(tmp) {
            int j = i-h[tmp];
            if(j >= 0) ans += (ll) term[tmp] * val[st[j]];

            tmp = super[tmp];
        }
    }

    cout << ans << "\n";
	
	return 0;
}

