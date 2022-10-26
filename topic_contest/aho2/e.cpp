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

const int SUML = 100 + 5;
const int E = 26;
const int mod = 239;

int l, n;
int nodes = 1;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];

void insert(const string& s) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = s[i]-'a';
        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
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

        if(term[suf[u]]) super[u] = suf[u];
        else super[u] = super[suf[u]];

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

typedef vector<vi> Mat;

int sum(int a, int b) {
    int ans = (a+b)%mod;
    return (ans+mod)%mod;
}

int mul(int a, int b) {
    return a*b%mod;
}

Mat mul_mat(const Mat& A, const Mat& B) {
    int a = A.size(), b = A[0].size(), c = B[0].size();
    Mat C(a, vi(b, 0));

    for(int i = 0; i < a; i++) {
        for(int k = 0; k < c; k++) {
            for(int j = 0; j < b; j++) {
                C[i][k] = sum(C[i][k], mul(A[i][j], B[j][k]));
            }
        }
    }

    return C;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin >> l >> n;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        insert(s);
    }

    build();

    Mat A(nodes, vi(nodes, 0));

    for(int from = 0; from < nodes; from++) {
        if(term[from]) {
            A[from][from] += 26;
            continue;
        }

        for(int c = 0; c < E; c++) {
            int to = go[from][c];
            if(!term[to] and super[to]) to = super[to];
            
            A[to][from]++;
        }
    }

    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++)
            A[i][j] %= mod;

    Mat M(nodes, vi(nodes, 0));
    
    for(int i = 0; i < nodes; i++)
        M[i][i] = 1;

    while(l) {
        if(l&1) {
            M = mul_mat(A, M);
        }
        A = mul_mat(A, A);
        l >>= 1;
    }

    Mat res(nodes, vi(1, 0));
    res[0][0] = 1;

    res = mul_mat(M, res);
    int ans = 0;

    for(int i = 0; i < nodes; i++)
        if(term[i]) ans = sum(ans, res[i][0]);

    cout << ans << "\n";

    return 0;
}
