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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    struct Block {
        int w, s, v;
    };

    vector<Block> blocks;

    for(int i = 0; i < n; i++) {
        int w, s, v; cin >> w >> s >> v;
        blocks.pb({w, s, v});
    }

    sort(all(blocks), [](Block& a, Block& b) {
            return a.s + a.w < b.s + b.w;
            });

    bool cmp = true;

    for(int i = 0; i < n-1; i++) {
        if(!(blocks[i].s + blocks[i].w <= blocks[i+1].s + blocks[i+1].w)) {
            cmp = 0;
        }
    }

    assert(cmp);

    const int maxw = 2e4 + 5;

    vector<ll> dp(maxw, -1);
    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        vector<ll> ndp = dp;
        
        for(int j = 0; j <= blocks[i].s; j++) {
            if(dp[j] == -1) continue;
            int W = j + blocks[i].w;
            if(W < maxw) {
                ndp[W] = max(ndp[W], dp[j] + blocks[i].v);
            }
        }

        dp = ndp;
    }

    cout << *max_element(all(dp)) << "\n";
	
    return 0;
}


