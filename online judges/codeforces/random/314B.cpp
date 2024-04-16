#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int b, d; cin >> b >> d;
    string a, c; cin >> a >> c;

    int n = a.size(), m = c.size();
    const int LOGN = 40;
    const int maxn = 105;

    ii nxt[maxn][maxn][LOGN];

    memset(nxt, -1, sizeof(nxt));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] != c[j]) continue;
            char nxt_letter = c[(j+1) % m];

            for(int k = i + 1; k < n; k++) {
                if(a[k] == nxt_letter) {
                    nxt[i][j][0] = {k, 0};
                    break;
                }
            }

            if(nxt[i][j][0].first != -1) continue;

            for(int k = 0; k <= i; k++) {
                if(a[k] == nxt_letter) {
                    nxt[i][j][0] = {k, 1};
                    break;
                }
            }
        }
    }

    for(int l = 1; l < LOGN; l++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nxt[i][j][0].first == -1) continue;
                ii mid = nxt[i][j][l-1];

                if(mid.first == -1) continue;

                ii rig = nxt[mid.first][(j + (1ll << (l-1))) % m][l-1];
                
                if(rig.first == -1) continue;

                nxt[i][j][l] = {rig.first, mid.second + rig.second};
            }
        }
    }

    auto get = [&](ll k) {
        if(k < 0) return 0ll;

        int pos = -1, curr = 0;

        for(int i = 0; i < n; i++) {
            if(c[0] == a[i]) {
                pos = i;
                break;
            }
        }

        if(pos == -1) return (ll) 1e18;

        ll ans = 0;
        for(int i = LOGN; i >= 0; i--) {
            if((k >> i)&1) {
                ii ne = nxt[pos][curr][i];
                if(ne.first == -1) return (ll) 1e18;

                ans += ne.second;
                pos = ne.first;
                curr = (curr + (1ll << i)) % m;
            }
        }

        return ans;
    };

    //cout << get(m * d) << endl;

    ll l = 0, r = (ll) 1e9;

    while(l < r) {
        ll tm = (l+r+1) >> 1;

        if(get(tm * m * d - 1) <= b-1) l = tm;
        else r = tm-1;
    }

    cout << l << "\n";

	
    return 0;
}


