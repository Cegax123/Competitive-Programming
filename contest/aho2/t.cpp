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

const ll mod = 1e9+7;
const int SUML = 200 + 5;
const int E = 20;

int n, m, k;
int nodes = 1;
int suf[SUML];
int term[SUML];
int go[SUML][E];
int val[SUML];

void insert(const vi& num, int x) {
    int pos = 0;
    for(int i = 0; i < (int) num.size(); i++) {
        int nxt = num[i];
        if(go[pos][nxt] == 0) {
            go[pos][nxt] = nodes++;
        }
        pos = go[pos][nxt];
    }
    val[pos] += x;
    term[pos]++;
}

void build(int src=0) {
    queue<int> Q;
    Q.emplace(src);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
    
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

ll sum(ll a, ll b, ll c) {
    ll ans = (a+b)%c;
    return (ans+c)%c;
}

vi L, R;
int dp[200+5][200+5][500+5][2][2];

ll call(int pos, int state, int value, int f, int t) {
    if(pos == (int) R.size()) 
        return 1;
    
    if(dp[pos][state][value][f][t] != -1) 
        return dp[pos][state][value][f][t];

    if(state == nodes) {
        ll ans = 0;

        if(L[pos] == 0) ans = call(pos+1, state, value, 1, 0);

        state = 0;
        
        int lmt = R[pos];
        if(f) lmt = m-1;

        int st = L[pos];
        st = max(st, 1);

        for(int d = st; d <= lmt; d++) {
            int n_state = go[state][d];
            int n_value = value + val[n_state];

            if(n_value > k) continue;

            int nf = f;
            if(f == 0 and d < lmt) nf = 1;

            int nt = t;
            if(t == 0 and d > L[pos]) nt = 1;

            ans = sum(ans, call(pos+1, n_state, n_value, nf, nt), mod);
        }

        return ans;
    }

    int lmt = R[pos];
    if(f) lmt = m-1;

    int st = L[pos];
    if(t) st = 0;

    ll ans = 0;

    for(int d = st; d <= lmt; d++) {
        int n_state = go[state][d];
        int n_value = value + val[n_state];

        if(n_value > k) continue;

        int nf = f;
        if(f == 0 and d < lmt) nf = 1;

        int nt = t;
        if(t == 0 and d > st) nt = 1;

        ans = sum(ans, call(pos+1, n_state, n_value, nf, nt), mod);
    }

    return dp[pos][state][value][f][t] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    
    int l; cin >> l;
    for(int i = 0; i < l; i++) {
        int d; cin >> d;
        L.pb(d);
    }

    cin >> l;
    for(int i = 0; i < l; i++) {
        int d; cin >> d;
        R.pb(d);
    }

    reverse(all(L));

    while(L.size() < R.size())
        L.pb(0);

    reverse(all(L));

    for(int i = 0; i < n; i++) {
        cin >> l;

        vi v;

        for(int j = 0; j < l; j++) {
            int d; cin >> d;
            v.pb(d);
        }

        int x; cin >> x;

        insert(v, x);
    }

    build();

    memset(dp, -1, sizeof(dp));
    cout << call(0, nodes, 0, 0, 0) << "\n";

    return 0;
}

