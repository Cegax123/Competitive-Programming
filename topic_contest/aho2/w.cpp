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

const int maxn = 1e5+5;
const int SQN = 350;

const int E = 26;

struct AC {
    int nodes;
    vector<vi> go;
    vi suf, term, super;
    vi val, ocurr;
    vi used_nodes;

    AC(): nodes(0) {node();}

    int node() {
        go.emplace_back(E, 0);
        suf.emplace_back(0);
        term.emplace_back(0);
        super.emplace_back(0);

        val.emplace_back(0);
        ocurr.emplace_back(0);

        return nodes++;
    }

    int insert(const string& s) {
        int pos = 0;

        for(int i = 0; i < (int) s.size(); i++) {
            int nxt = s[i]-'a';

            if(go[pos][nxt] == 0)
                go[pos][nxt] = node();

            pos = go[pos][nxt];
        }

        term[pos]++;
        return pos;
    }

    void build(int src=0) {
        queue<int> Q;
        Q.emplace(src);
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();

            if(term[suf[u]]) super[u] = suf[u];
            else super[u] = super[suf[u]];

            val[u] = val[suf[u]] + term[u];

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

    int obtain_occurrences(const string& s) {
        int pos = 0;
        int ans = 0;

        for(int i = 0; i < (int) s.size(); i++) {
            int nxt = s[i]-'a';
            pos = go[pos][nxt];
            
            ans += val[pos];
        }

        return ans;
    }

    void give_occurrences(const string& s) {
        int pos = 0;

        for(int i = 0; i < (int) s.size(); i++) {
            int nxt = s[i]-'a';
            pos = go[pos][nxt];

            int tmp = (term[pos] ? pos : super[pos]);

            while(tmp) {
                ocurr[tmp]++;
                used_nodes.pb(tmp);

                tmp = super[tmp];
            }
        }
    }

    void clear_ocurrences() {
        for(int node : used_nodes)
            ocurr[node] = 0;

        used_nodes.clear();
    }
};

AC total;
AC block[SQN];

struct Query {
    int l, r, id;
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, q; cin >> n >> q;

    int node[n];
    string s[n];

    for(int i = 0; i < n; i++) {
        cin >> s[i];
        
        node[i] = total.insert(s[i]);
        block[i/SQN].insert(s[i]);
    }

    total.build();

    for(int i = 0; i < SQN; i++)
        block[i].build();

    vector<Query> queries[n];
    vector<ll> ans(q, 0);

    for(int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k;
        l--; r--; k--;

        queries[k].pb({l, r, i});
    }

    for(int v = 0; v < n; v++) {
        int cnt[SQN];

        for(int i = 0; i < SQN; i++)
            cnt[i] = block[i].obtain_occurrences(s[v]);

        total.give_occurrences(s[v]);

        for(auto& Q : queries[v]) {
            int L = Q.l/SQN + 1, R = Q.r/SQN - 1;

            for(int i = L; i <= R; i++) {
                ans[Q.id] += cnt[i];
            }


            if(L <= R) {
                for(int i = Q.l; i < L * SQN; i++) 
                    ans[Q.id] += total.ocurr[node[i]];

                for(int i = (R+1) * SQN; i <= Q.r; i++) 
                    ans[Q.id] += total.ocurr[node[i]];
            }
            else {
                for(int i = Q.l; i <= Q.r; i++)
                    ans[Q.id] += total.ocurr[node[i]];
            }

        }

        total.clear_ocurrences();
    }

    for(int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
	
    return 0;
}

