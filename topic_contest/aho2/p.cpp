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

const int SUML = 1e5 + 5;
const int E = 26;
const int INF = 1e9;

int n;
int nodes;
int suf[SUML];
bool term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];

struct Query {
    int k, node, id, ans;
    string s;
    vi pos;
};

vector<Query> queries;

void insert(const string& s, int j){
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++){
        int nxt = s[i] - 'a';
        if(trie[pos][nxt] == 0){
            trie[pos][nxt] = nodes++;
        }
        pos = trie[pos][nxt];
    }
    term[pos]=1;
    queries[j].node = pos;
}

void BFS(int src){
    queue<int> Q;
    Q.emplace(src);
    while(!Q.empty()){
        int u = Q.front(); Q.pop();

        if(term[suf[u]]) super[u] = suf[u];
        else super[u] = super[suf[u]];

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

vi positions[SUML];

void process(const string& t) {
    int pos = 0;
    for(int i = 0; i < (int) t.size(); i++) {
        int nxt = t[i]-'a';
        pos = go[pos][nxt];

        int tmp = pos;
        while(tmp) {
            positions[tmp].pb(i);
            tmp = super[tmp];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string t; cin >> t;

    nodes = 1;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int k; string s; cin >> k >> s;
        Query x;

        x.k = k;
        x.s = s;
        x.id = i;

        queries.pb(x);
        insert(s, i);
    }

    BFS(0);
    process(t);

    for(int i = 0; i < n; i++) {
        queries[i].pos = positions[queries[i].node];
    }

    for(auto& q : queries) {
        if(q.k > (int) q.pos.size()) {
            q.ans = -1;
            continue;
        }

        q.ans = INF;
        for(int i = q.k-1; i < (int) q.pos.size(); i++) {
            int r = q.pos[i];
            int l = q.pos[i-q.k+1]-q.s.size()+1;
            q.ans = min(q.ans, r-l+1);
        }
    }

    int ans[n];
    for(int i = 0; i < n; i++) {
        ans[queries[i].id] = queries[i].ans;
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
