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

const int maxn = 3e5;
const int b = 30;
const int SUML = maxn * b + 5;

int nodes;
int trie[SUML][2];
ii val[SUML];
int p[maxn+5];
int n, k;

int get_val(int x, int j) {
    int pos = 0;
    int ans = 1;

    for(int i = b; i >= 0; i--) {
        int nxt = (x >> i) & 1;
        int curr = (k >> i) & 1;

        if(i == 0 and trie[pos][nxt^curr]) {
            int nxt_node = trie[pos][nxt^curr];
            if(ans < val[nxt_node].first+1) {
                ans = val[nxt_node].first+1;
                p[j] = val[nxt_node].second;
            }
        }

        if(curr == 0 and trie[pos][1^nxt]) {
            if(ans < val[trie[pos][1^nxt]].first+1) {
                ans = val[trie[pos][1^nxt]].first+1;
                p[j] = val[trie[pos][1^nxt]].second;
            }
        }

        if(trie[pos][curr^nxt] == 0) 
            break;

        pos = trie[pos][curr^nxt];
    }

    return ans;
}

void insert(int x, int curr_val, int j) {
    int pos = 0;
    for(int i = b; i >= 0; i--) {
        int nxt = (x >> i) & 1;
        
        if(val[pos].first < curr_val) {
            val[pos].first = curr_val;
            val[pos].second = j;
        }

        if(trie[pos][nxt] == 0)
            trie[pos][nxt] = nodes++;

        pos = trie[pos][nxt];
    }

    if(val[pos].first < curr_val) {
        val[pos].first = curr_val;
        val[pos].second = j;
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    nodes = 1;
    memset(p, -1, sizeof(p));

    cin >> n >> k;
    vii a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(all(a));

    for(int i = 0; i < n; i++) {
        int curr_val = get_val(a[i].first, a[i].second+1);
        insert(a[i].first, curr_val, a[i].second+1);
    }

    vi ans;
    int k = val[0].second;

    while(k != -1) {
        ans.pb(k);
        k = p[k];
    }

    reverse(all(ans));

    if(ans.size() == 1) {
        cout << "-1\n";
    }
    else {
        cout << ans.size() << "\n";
        for(int x : ans)
            cout << x << " ";
    }
	
	return 0;
}

