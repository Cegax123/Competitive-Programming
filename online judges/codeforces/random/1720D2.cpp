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
const int E = 2;
const int maxn = 3e5 + 5;

struct Node {
    int ans[2];
    Node() {
        ans[0] = ans[1] = 0;
    }
};

ii get_min(int ba, int bx) {
    if(ba == 1 and bx == 1) return {0, 0};
    if(ba == 1 and bx == 0) return {1, 1};
    if(ba == 0 and bx == 1) return {1, 0};
    if(ba == 0 and bx == 0) return {0, 1};
    return {-1, -1};
}

int trie[maxn * L][E];
Node val[maxn * L];
int nodes = 1;
int total = 1;

void process(int a, int x) {
    int pos = 0;
    int ans = 1;
    for(int i = L-1; i >= 0; i--) {
        int ba = (a >> i)&1, bx = (x >> i)&1;
        ii e = get_min(ba, bx);
        int wa = e.first, wx = e.second;

        if(trie[pos][wx]) {
            int nxt = trie[pos][wx];
            ans = max(ans, val[nxt].ans[wa]+1);
        }

        if(trie[pos][bx] == 0) {
            trie[pos][bx] = nodes++;
        }

        pos = trie[pos][bx];
    }

    pos = 0;

    total = max(total, ans);

    for(int i = L-1; i >= 0; i--) {
        int ba = (a >> i)&1, bx = (x >> i)&1;

        pos = trie[pos][bx];
        val[pos].ans[ba] = max(val[pos].ans[ba], ans);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            process(a[i], a[i] ^ i);
        }

        cout << total << "\n";


        for(int i = 0; i < nodes; i++) {
            trie[i][0] = trie[i][1] = 0;
            val[i] = Node();
        }
        nodes = 1;
        total = 1;
    }

    return 0;
}


