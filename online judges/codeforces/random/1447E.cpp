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
const int L = 40;
const int SUMS = maxn * L;
const int E = 2;

int trie[SUMS][E], frec[SUMS];
int ind[SUMS];
int nodes = 1;

void insert(int x, int id) {
    int pos = 0;
    for(int i = L-1; i >= 0; i--) {
        int nxt = (x >> i)&1;
        if(trie[pos][nxt] == 0) 
            trie[pos][nxt] = nodes++;

        pos = trie[pos][nxt];
        frec[pos]++;
    }

    ind[pos] = id;
}

void erase(int x) {
    int pos = 0;
    for(int i = L-1; i >= 0; i--) {
        int nxt = (x >> i) & 1;
        pos = trie[pos][nxt];
        frec[pos]--;
    }
}

int find(int x) {
    int pos = 0;
    for(int i = L-1; i >= 0; i--) {
        int curr = (x >> i) & 1;
        if(frec[trie[pos][curr]]) 
            pos = trie[pos][curr];
        else 
            pos = trie[pos][curr ^ 1];
    }

    return ind[pos];
}

bool used[maxn];
vi adj[maxn];

void dfs(int v) {
    used[v] = 1;
    for(int to : adj[v])
        if(!used[to]) dfs(to);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        insert(a[i], i);
    }

    for(int i = 0; i < n; i++) {
        erase(a[i]);
        int j = find(a[i]);
        insert(a[i], i);

        cout << i << " " << j << endl;

        adj[i].pb(j);
        adj[j].pb(i);
    }

    int cnt = 0;

    for(int i = 0; i < n; i++)
        if(!used[i]) {
            dfs(i);
            cnt++;
        }

    cout << cnt-1 << "\n";
	
    return 0;
}


