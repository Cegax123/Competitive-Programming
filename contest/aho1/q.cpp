// UNSOLVED

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

const int maxn = 505;
const int SUML = 500 * 5000 + 5;
const int E = 70;

int n;
int nodes;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];

ll freq[SUML];
int ver[maxn];
int pos_arr[SUML];

string sgm;

int get_id(char c) {
    if(c >= 'a' and c <= 'z') return c-'a';
    if(c >= 'A' and c <= 'Z') return c-'A'+26;
    else return c-'0'+52;
}

void insert(const string& s, int ind){
	int pos = 0;
	for(int i = 0; i < (int) s.size(); i++){
		int nxt = get_id(s[i]);
		if(trie[pos][nxt] == 0){
			trie[pos][nxt] = nodes++;
		}
		pos = trie[pos][nxt];
	}
	term[pos]++;
    ver[ind] = pos;
}

void build(int src=0){
	queue<int> Q;
	Q.emplace(src);
	while(!Q.empty()){
		int u = Q.front(); Q.pop();

		if(term[suf[u]]) super[u] = suf[u];
		else super[u] = super[suf[u]];

		// cout << u << endl;
		for(char x : sgm){
            int c = get_id(x);
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


void process(string s) {
    int pos = 0;

    for(int i = 0; i < (int) s.size(); i++) {
        if(s[i] == '-') {
            pos = 0;
            continue;
        }

        int nxt = get_id(s[i]);
        pos = go[pos][nxt];

        int tmp = pos;
        if(!term[pos]) tmp = super[pos];

        if(tmp) freq[tmp]++;
    }
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(char c = 'a'; c <= 'z'; c++)
        sgm += c;

    for(char c = 'A'; c <= 'Z'; c++)
        sgm += c;

    for(char c = '0'; c <= '9'; c++)
        sgm += c;

    nodes = 1;

    cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        insert(s, i);
    }

    build();

    int q; cin >> q;
    while(q--) {
        string s; cin >> s;
        process(s);
    }

	return 0;
}

