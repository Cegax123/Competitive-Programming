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

typedef unsigned long long ull;
const int SUML = 25 + 5;
const int E = 26;

int n, L;
int nodes;
int suf[SUML];
int term[SUML];
int trie[SUML][E];
int super[SUML];
int go[SUML][E];

void init() {
    nodes = 1;

    memset(trie, 0, sizeof(trie));
    memset(term, 0, sizeof(term));
    memset(go, 0, sizeof(go));
    memset(suf, 0, sizeof(suf));
    memset(super, 0, sizeof(super));
}

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

typedef vector<vector<ull>> Mat;

Mat mul_mat(const Mat& A, const Mat& B) {
    int a = A.size(), b = A[0].size(), c = B[0].size();
    Mat C(a, vector<ull>(c, 0));
 
    for(int i = 0; i < a; i++) {
        for(int k = 0; k < c; k++) {
            for(int j = 0; j < b; j++) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }
 
    return C;
}

void print_matrix(Mat A) {
    for(int i = 0; i < (int) A.size(); i++) {
        for(int j = 0; j < (int) A[0].size(); j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> L;

        init();
        
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            insert(s);
        }

        build();

        nodes++;
        Mat A(nodes, vector<ull> (nodes, 0));

        for(int from = 0; from < nodes-1; from++) {
            if(term[from]) {
                A[from][from] += E;
                continue;
            }

            for(int c = 0; c < E; c++) {
                int to = go[from][c];

                if(!term[to] and super[to]) to = super[to];

                A[to][from]++;
            }
        }

        A[nodes-1][nodes-1]++;
        A[0][nodes-1]++;

        Mat M = A;

        while(L) {
            if(L&1)
                M = mul_mat(A, M);
            L >>= 1;
            A = mul_mat(A, A);
        }

        Mat res(nodes, vector<ull> (1, 0));
        res[nodes-1][0] = 1;

        res = mul_mat(M, res);

        ull ans = 0;
        for(int i = 0; i < nodes; i++) 
            if(term[i]) 
                ans += res[i][0];

        cout << ans << "\n";

    }

    return 0;
}
