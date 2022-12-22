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

const int L = 30;
const int B = 2;
const int maxn = 2e5;

int trie[maxn * L][B];
int h[maxn * L];
int nodes = 1;

int ans[maxn * L];

void insert(int x) {
    int pos = 0;
    for(int i = L-1; i >= 0; i--) {
        int nxt = (x >> i)&1;
        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
            h[trie[pos][nxt]] = h[pos] + 1;
        }
        pos = trie[pos][nxt];
    }
}

void comp(int v) {
    int Lv = trie[v][0], Rv = trie[v][1];

    if(Lv) comp(Lv);
    if(Rv) comp(Rv);

    if(Lv and Rv) {
        ans[v] += (1 << (L-1-h[v]));
        ans[v] += min(ans[Lv], ans[Rv]);
    }
    else if(Lv) {
        ans[v] = ans[Lv];
    }
    else if(Rv) {
        ans[v] = ans[Rv];
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        insert(a);
    }

    comp(0);
    cout << ans[0] << "\n";
	
    return 0;
}


