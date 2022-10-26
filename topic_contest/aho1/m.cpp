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

const int maxn = 1000 + 5;
const int SUML = 2e6 + 5;
const int E = 26;

struct Ans {
    int sx=-1, sy=-1;
    char d;
};

vector<Ans> ans;

int n, m, k;
char board[maxn][maxn];

int nodes;
int id[SUML];
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];
int h[SUML];

void init() {
    nodes = 1;

    ans.clear(); ans.resize(k);
	memset(trie, 0, sizeof(trie));
	memset(term, 0, sizeof(term));
	memset(go, 0, sizeof(go));
	memset(suf, 0, sizeof(suf));
	memset(super, 0, sizeof(super));
    memset(h, 0, sizeof(h));
}

void insert(const string& s, int ind){
	int pos = 0;
	for(int i = 0; i < (int) s.size(); i++){
		int nxt = s[i] - 'A';
		if(trie[pos][nxt] == 0){
			trie[pos][nxt] = nodes++;
            h[trie[pos][nxt]] = h[pos]+1;
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

string dir = "ABCDEFGH";

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isValid(int x, int y) {
    if(x >= 0 and x < n and y >= 0 and y < m) return 1;
    return 0;
}

void process(int sx, int sy, int d) {
    int pos = 0;

    while(isValid(sx, sy)) {
        int nxt = board[sx][sy]-'A';
        pos = go[pos][nxt];

        int tmp = term[pos] ? pos : super[pos];

        while(tmp) {
            int ind = id[tmp];
            
            ans[ind].sx = sx - h[tmp] * dx[d] + dx[d];
            ans[ind].sy = sy - h[tmp] * dy[d] + dy[d];
            ans[ind].d = dir[d];

            tmp = super[tmp];
        }

        sx += dx[d];
        sy += dy[d];
    }
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m >> k;

        for(int i = 0; i < n; i++)
            cin >> board[i];

        init();

        for(int i = 0; i < k; i++) {
            string s; cin >> s;
            insert(s, i);
        }

        build();

        for(int i = 0; i < n; i++) {
            process(i, 0, 2);
            process(i, m-1, 6);
            process(i, 0, 1);
            process(i, 0, 3);
            process(i, m-1, 5);
            process(i, m-1, 7);
        }

        for(int j = 0; j < m; j++) {
            process(0, j, 4);
            process(n-1, j, 0);
            process(0, j, 3);
            process(0, j, 5);
            process(n-1, j, 1);
            process(n-1, j, 7);
        }

        for(int i = 0; i < k; i++)
            cout << ans[i].sx << " " << ans[i].sy << " " << ans[i].d << "\n";

        cout << "\n";
    }


	return 0;
}
