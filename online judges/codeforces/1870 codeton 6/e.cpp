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

const int maxn = 100;
const int L = 15;

int nodes[maxn];
int trie[maxn][maxn * L][2];
int r[maxn];

int get(int t, int x) {
    int pos = 0;
    int ans = 0;

    for(int i = L-1; i >= 0; i--) {
        int b = (x >> i)&1;
        int need = (1 ^ b) ^ ((r[t] >> i)&1);

        if(trie[t][pos][need] == 0 and trie[t][pos][1^need] == 0) {
            return -1;
        }

        if(trie[t][pos][need]) {
            ans |= (1 << i);
            pos = trie[t][pos][need];
        }
        else {
            pos = trie[t][pos][1^need];
        }
    }
    return ans;
}

void insert(int t, int x) {
    int pos = 0;

    for(int i = L-1; i >= 0; i--) {
        int b = (x >> i)&1;
        b ^= ((r[t] >> i)&1);

        if(trie[t][pos][b] == 0) {
            trie[t][pos][b] = nodes[i]++;
        }

        pos = trie[t][pos][b];
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n+1];
        for(int i = 1; i <= n; i++) cin >> a[i];
        
        for(int i = 0; i <= n; i++) {
            nodes[i] = 1;
            r[i] = 0;
        }

        int ans = 0;

        

        for(int i = 1; i <= n; i++) {
            vi cnt(n+1, 0);
            int mex = 0;

            for(int j = i-1; j >= 0; j--) {
                cnt[a[j+1]]++;
                while(cnt[mex]) mex++;

                if(get(j, mex) == 7) {
                    cout << i << " " << j << " " << mex << endl;
                }

                ans = max(ans, get(j, mex));


                insert(j, r[j]);
                r[j] ^= mex;
            }
        }

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= L * n; j++) {
                trie[i][j][0] = trie[i][j][1] = 0;
            }
        }

        cout << ans << "\n";
    }

	
    return 0;
}


