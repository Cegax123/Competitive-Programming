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

const int maxn = 5e5 + 5;
const int LOGN = 20;
int t[4 * maxn];

int s[maxn], nxt[maxn], f[maxn][LOGN];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = s[tl];
    }
    else {
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm+1, tr);

        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

ii find(int v, int tl, int tr, int l, int r, int x) {
    if(r < tl or tr < l) return {-1, -1};
    if(tl == l and tr == r and t[v] < x) return {-1, -1};

    if(tl == tr) return {t[v], tl};
    else {
        int tm = (tl + tr) >> 1;
        ii ansL = find(v * 2, tl, tm, l, min(r, tm), x);

        if(ansL.first != -1) return ansL;

        return find(v * 2 + 1, tm+1, tr, max(tm+1, l), r, x);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(r < tl or tr < l) return -1; 

    if(tl == l and tr == r) {
        return t[v];
    }
    else {
        int tm = (tl + tr) >> 1;
        return max(query(v * 2, tl, tm, l, min(r, tm)),
                    query(v * 2 + 1, tm+1, tr, max(tm+1, l), r));
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;

        for(int i = 0; i < n; i++)
            cin >> s[i];

        s[n] = 1e9 + 5;

        build(1, 0, n);

        f[n][0] = n;
        for(int i = 0; i < n; i++) {
            ii ans = find(1, 0, n, i+1, n, s[i]-1);
            f[i][0] = ans.second;
        }

        for(int j = 1; j < LOGN; j++) {
            for(int i = 0; i <= n; i++) {
                f[i][j] = f[f[i][j-1]][j-1];
            }
        }

        while(q--) {
            int l, r; cin >> l >> r;
            l--; r--;

            int mx = query(1, 0, n, l, r);
            int pos = find(1, 0, n, l, r, mx).second;

            int rpos = pos;
            int num_steps = 0;

            for(int i = LOGN-1; i >= 0; i--) {
                if(f[rpos][i] <= r) {
                    //cout << i << " ";
                    num_steps += (1 << i);
                    rpos = f[rpos][i];
                }
            }

            //cout << pos << " " << rpos << endl;
            //cout << num_steps << endl;

            cout << s[pos]+1 - (s[pos]-s[rpos] == num_steps) << "\n";
        }
    }

	
    return 0;
}


