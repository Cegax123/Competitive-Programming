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

const int maxn = 2e5 + 5;
const int L = 30;
const int E = 2;

int trie[maxn * L][E];
int cnt[maxn * L], h[maxn * L], val[maxn * L];
bool terminal[maxn * L];
int nodes = 1;

void insert(int x) {
    int pos = 0;
    for(int i = L-1; i >= 0; i--) {
        int nxt = (x >> i)&1;

        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
            h[trie[pos][nxt]] = h[pos]+1;
            val[trie[pos][nxt]] = nxt;
        }

        pos = trie[pos][nxt];
    }

    cnt[pos] = 1;
    terminal[pos] = 1;
}

void compute_cnt(int v) {
    for(int b = 0; b < 2; b++) {
        int to = trie[v][b];
        if(to) {
            compute_cnt(to);
            cnt[v] += cnt[to];
        }
    }
}

ll ans[maxn * L];
vector<int> c;

void find_terminals(int v, int x) {
    int curr = x | (val[v] << (L - h[v]));

    if(terminal[v]) {
        c.pb(curr);
        return;
    }

    for(int b = 0; b < 2; b++) {
        int to = trie[v][b];
        if(to) {
            find_terminals(to, curr);
        }
    }
}

int min_x;

int find_min(int v, int x) {
    int ans = (1 << (L-h[v]));
    int pos = v;

    for(int i = L - h[v] - 1; i >= 0; i--) {
        int b = (x >> i)&1;

        if(trie[pos][b]) {
            pos = trie[pos][b];
        }
        else {
            pos = trie[pos][1^b];
            ans ^= (1 << i);
        }
    }

    return ans;
}

void compute_ans(int v) {
    int son = 0;
    for(int b = 0; b < 2; b++) {
        int to = trie[v][b];
        if(to) {
            compute_ans(to);
            ans[v] += ans[to];
            son++;
        }
    }

    if(son < 2) return;

    int L = trie[v][0], R = trie[v][1];

    if(cnt[L] < cnt[R]) find_terminals(L, 0);
    else find_terminals(R, 0);

    int result = -1;
    int y = (cnt[L] < cnt[R] ? R : L);
        
    for(int x : c) {
        int curr = find_min(y, x);
        if(result == -1 or curr < result) result = curr;
    }

    ans[v] += result;


    //cout << v << ": ";
    //for(int x : c) cout << x << " ";
    //cout << "\n";

    c.clear();
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        insert(a);
    }

    compute_cnt(0);
    compute_ans(0);

    cout << ans[0] << "\n";
	
    return 0;
}


