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

void expr(int, bool);
void number(int);

int p, m;

string s;
int pos = 0;

const int maxp = 100+5;
const int maxn = 1e4+5;
const int INF = 1e9;

int min_val[maxn][maxp], max_val[maxn][maxp];

struct Node {
    int L, R, p;
    int val, children;
    int id;
};

vector<Node> nodes;


void expr(int p, bool L) {
    if(p >= 0) {
        if(L) nodes[p].L = nodes.size();
        else nodes[p].R = nodes.size();
    }

    if(s[pos] == '(') {
        int ind = nodes.size();
        nodes.pb({-1, -1, p, 0, 2, ind});

        pos++;

        expr(ind, 1);

        pos++;

        expr(ind, 0);

        pos++;
    }

    else {
        number(p);
    }
}

void number(int p) {
    int ind = nodes.size();
    nodes.pb({-1, -1, p, s[pos]-'0', 0, ind});
    pos++;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxp; j++) {
            min_val[i][j] = INF;
            max_val[i][j] = -INF;
        }
    }

    cin >> s >> p >> m;
	
    expr(-1, 0);

    int n = nodes.size();


	int sign = 1;
    if(m < p) sign = -1;

    int cnt = min(m, p);

    queue<Node> q;

    for(int i = 0; i < n; i++) 
        if(nodes[i].children == 0)
            q.push(nodes[i]);

    while(!q.empty()) {
        Node v = q.front(); q.pop();

        if(v.val) {
            min_val[v.id][0] = max_val[v.id][0] = v.val;
        }
        else {
            for(int i = 0; i <= cnt; i++) {
                for(int j = 0; j <= i; j++) {
                    if(sign == 1) {
                        max_val[v.id][i] = max(max_val[v.id][i], max_val[v.L][j] - min_val[v.R][i-j]);
                        if(j < i) max_val[v.id][i] = max(max_val[v.id][i], max_val[v.L][j] + max_val[v.R][i-j-1]);

                        min_val[v.id][i] = min(min_val[v.id][i], min_val[v.L][j] - max_val[v.R][i-j]);
                        if(j < i) min_val[v.id][i] = min(min_val[v.id][i], min_val[v.L][j] + min_val[v.R][i-j-1]);
                    }
                    else {
                        max_val[v.id][i] = max(max_val[v.id][i], max_val[v.L][j] + max_val[v.R][i-j]);
                        if(j < i) max_val[v.id][i] = max(max_val[v.id][i], max_val[v.L][j] - min_val[v.R][i-j-1]);

                        min_val[v.id][i] = min(min_val[v.id][i], min_val[v.L][j] + min_val[v.R][i-j]);
                        if(j < i) min_val[v.id][i] = min(min_val[v.id][i], min_val[v.L][j] - max_val[v.R][i-j-1]);
                    }
                }
            }
        }

        if(v.p == -1) continue;

        nodes[v.p].children--;

        if(nodes[v.p].children == 0)
            q.push(nodes[v.p]);
    }

    cout << max_val[0][cnt] << "\n";
	
    return 0;
}
