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
int super[SUML];
int go[SUML][E];
vi ind[SUML];
bool vis[SUML];

void insert(const string& s, int j){
    int pos = 0;
	for(int i = 0; i < (int) s.size(); i++){
	    int nxt = s[i] - 'a';
	    if(go[pos][nxt] == 0){
	        go[pos][nxt] = nodes++;
	    }
	    pos = go[pos][nxt];
	}
    ind[pos].pb(j);
    term[pos]++;
}

void build(int src=0){
    queue<int> Q;
    Q.emplace(src);
    while(!Q.empty()){
	    int u = Q.front(); Q.pop();

	    if(term[suf[u]]) super[u] = suf[u];
	    else super[u] = super[suf[u]];

	    for(int c = 0; c < E; c++){
	        if(go[u][c]){
	            int v = go[u][c];
	            Q.emplace(v);
                
	            suf[v] = u == 0 ? 0 : go[suf[u]][c];
            }
	        else{
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

    build();
    
    string t; cin >> t;
    int pos = 0;
    for(int i = 0; i < (int) t.size(); i++) {
        int nxt = t[i]-'a';
        pos = go[pos][nxt];

        int tmp = term[pos] ? pos : super[pos];

        while(tmp) {
            if(vis[tmp]) break;
            vis[tmp] = 1;
            tmp = super[tmp];
        }
    }

    bool ans[n];
    for(int i = 0; i < nodes; i++) {
        if(term[i] == 0) continue;
        for(int p : ind[i])
            ans[p] = vis[i];
    }

    for(int i = 0; i < n; i++) {
        cout << (ans[i] ? "YES\n" : "NO\n");
    }

    return 0;
}
