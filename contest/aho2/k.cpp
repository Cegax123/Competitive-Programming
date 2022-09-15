#include <bits/stdc++.h>
#include <valarray>
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

const int SUML = 100 + 5;
const int E = 50;

int n, m, p;
int nodes = 1;
int suf[SUML];
int term[SUML];
int go[SUML][E];
bool forb[SUML];
map<char, int> val;

void insert(const string& s) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = val[s[i]];
        if(go[pos][nxt] == 0) {
            go[pos][nxt] = nodes++;
        }
        pos = go[pos][nxt];
    }
    term[pos]++;
    forb[pos] = 1;
}

void build(int src=0) {
    queue<int> Q;
    Q.emplace(src);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();

        forb[u] |= forb[suf[u]];

        for(int c = 0; c < n; c++) {
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

vi sum(vi a, vi b) {
    if(a.empty() and b.empty()) {
        return vi(1, 0);
    }

    while(a.size() < b.size())
        a.pb(0);

    while(b.size() < a.size())
        b.pb(0);

    vi d(a.size(), 0);

    int c = 0;
    for(int i = 0; i < (int) a.size(); i++) {
        d[i] = a[i] + b[i] + c;
        c = d[i] / 10;
        d[i] %= 10;
    }

    while(c) {
        d.pb(c%10);
        c /= 10;
    }

    return d;
}

void print_bignum(vi a) {
    reverse(all(a));

    for(int d:a)
        cout << d;

    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> p;
    string sigm; cin >> sigm;

    for(int i = 0; i < n; i++)
        val[sigm[i]] = i;

    for(int i = 0; i < p; i++) {
        string s; cin >> s;
        insert(s);
    }

    build();

    vi dp[m+1][nodes];

    dp[0][0].pb(1);

    for(int i = 0; i < m; i++) {
        for(int v = 0; v < nodes; v++) {
            if(dp[i][v].empty()) continue;
            for(int c = 0; c < n; c++) {
                int n_state = go[v][c];
                if(forb[n_state]) continue;

                dp[i+1][n_state] = sum(dp[i+1][n_state], dp[i][v]);
            }
        }
    }

    vi ans(1, 0);

    for(int v = 0; v < nodes; v++) 
        if(!dp[m][v].empty()) ans = sum(ans, dp[m][v]);

    while(ans.back() == 0) 
        ans.pop_back();

    if(ans.empty())
        ans.pb(0);

    print_bignum(ans);
	
    return 0;
}
