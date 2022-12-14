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
bool term[maxn * L];
int ans[maxn * L];
int nodes = 1;

void insert(int x) {
    int pos = 0;
    for(int i = L-1; i >= 0; i--) {
        int b = (x >> i)&1;
        if(trie[pos][b] == 0) {
            trie[pos][b] = nodes++;
        }
        pos = trie[pos][b];
    }
    term[pos] = 1;
}

void solve(int v) {
    if(term[v]) {
        ans[v] = 1;
        return;
    }

    for(int b = 0; b < E; b++) {
        if(trie[v][b]) solve(trie[v][b]);
    }

    int L = trie[v][0], R = trie[v][1];

    if(L) ans[v] = ans[L] + (ans[R] ? 1 : 0);
    if(R) ans[v] = max(ans[v], ans[R] + (ans[L] ? 1 : 0));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        insert(a);
    }

    solve(0);

    cout << n - ans[0] << "\n";
	
    return 0;
}


