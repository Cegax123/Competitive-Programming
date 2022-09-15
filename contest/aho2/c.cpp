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

int n;
int nodes = 1;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
int L[SUML], R[SUML];
int h[SUML];
vi ind[SUML];
int deg[SUML];

void insert(const string& s, int j) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = s[i]-'a';
        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
            h[trie[pos][nxt]] = h[pos]+1;
        }
        pos = trie[pos][nxt];
    }
    ind[pos].pb(j);
    term[pos]++;
}

void build(int src=0) {
    queue<int> Q;
    Q.emplace(src);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();

        if(term[suf[u]]) super[u] = suf[u];
        else super[u] = super[suf[u]];

        if(term[u]) deg[u] = 0;

        for(int c = 0; c < E; c++) {
            if(trie[u][c]) {
                int v = trie[u][c];
                Q.emplace(v);

                go[u][c] = trie[u][c];
                suf[v] = u == 0 ? 0 : go[suf[u]][c];
            }
            else {
                go[u][c] = u == 0 ? 0 : go[suf[u]][c];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        insert(s, i);
    }

    memset(deg, -1, sizeof(deg));
    memset(L, -1, sizeof(L));
    memset(R, -1, sizeof(R));
    
    build();

    for(int i = 0; i < nodes; i++)
        if(term[i]) deg[super[i]]++;

    string t; cin >> t;
    int pos = 0;
    for(int i = 0; i < (int) t.size(); i++) {
        int nxt = t[i]-'a';
        pos = go[pos][nxt];

        int tmp = term[pos] ? pos : super[pos];
        
        if(L[tmp] == -1) {
            L[tmp] = R[tmp] = i-h[tmp]+1;
        }

        L[tmp] = min(L[tmp], i-h[tmp]+1);
        R[tmp] = max(R[tmp], i-h[tmp]+1);
    }

    queue<int> q;
    for(int i = 0; i < nodes; i++) 
        if(deg[i] == 0) q.push(i);

    vii ans(n);
    while(!q.empty()) {
        int v = q.front(); q.pop();

        for(int p : ind[v])
            ans[p] = {L[v], R[v]};

        if(v == 0) continue;

        int pv = super[v];
        
        if(L[v] != -1) {
            if(L[pv] == -1) {
                L[pv] = L[v] + (h[v]-h[pv]);
                R[pv] = R[pv] + (h[v]-h[pv]);
            }

            L[pv] = min(L[pv], L[v]+(h[v]-h[pv]));
            R[pv] = max(R[pv], R[v]+(h[v]-h[pv]));
        }

        deg[pv]--;
        if(deg[pv] == 0) q.push(pv);
    }


    for(int i = 0; i < n; i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
   
    return 0;
}

