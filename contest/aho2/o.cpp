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
const int E = 62;

int nodes = 1;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int go[SUML][E];
int val[SUML];
int h[SUML];

int get_val(const char& c) {
    if(c >= 'a' and c <= 'z') return c-'a';
    if(c >= 'A' and c <= 'Z') return c-'A'+26;
    return c-'0'+52;
}

void insert(const string& s) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = get_val(s[i]);
        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
            h[trie[pos][nxt]] = h[pos]+1;
        }
        pos = trie[pos][nxt];
    }
    term[pos]++;
}

void build(int src=0) {
    queue<int> Q;
    Q.emplace(src);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();

        if(term[u] and val[suf[u]] == 0) val[u] = h[u];
        else val[u] = val[suf[u]];

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
    
    string p; cin >> p;

    int k; cin >> k;

    for(int i = 0; i < k; i++) {
        string s; cin >> s;
        insert(s);
    }

    build();

    int n = p.size();

    int prev[n+2], nxt[n+2];
    
    for(int i = 1; i < n+2; i++) 
        prev[i] = i-1;
    
    for(int i = 0; i < n+1; i++)
        nxt[i] = i+1;

    int st[n+1];

    st[0] = 0;
    int curr_st = 0;

    for(int i = 1; i <= n; i++) {
        st[i] = go[curr_st][get_val(p[i-1])];

        if(val[st[i]]) {
            int tmp = i;

            for(int j = 0; j < val[st[i]]; j++) {
                prev[nxt[tmp]] = prev[tmp];
                nxt[prev[tmp]] = nxt[tmp];

                int _tmp = tmp;
                tmp = prev[tmp];

                nxt[_tmp] = prev[_tmp] = -1;
            }
            curr_st = st[tmp];
        }
        else curr_st = st[i];
    }

    if(prev[n+1] == 0) 
        cout << "\n";
    else {
        int st = 0;

        for(int i = 1; i <= n; i++) {
            if(nxt[i] != -1) {
                st = i;
                break;
            }
        }

        string ans;
        while(st != n+1) {
            ans += p[st-1];
            st = nxt[st];
        }

        cout << ans << "\n";
    }
	
    return 0;
}
