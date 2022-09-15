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

const int maxn = 4e5+5;
const int LOGN = 20;
const ll INF = (ll) 1e16;

ll w[maxn];
int go[maxn][LOGN];
ll sum[maxn][LOGN];

ll solve(int r, ll x) {
    int ans = 0;
    ll curr = w[r];
    int pos = r;

    for(int i = LOGN-1; i >= 0; i--) {
        if(curr + sum[pos][i] - w[pos] <= x) {
            curr += sum[pos][i]-w[pos];
            pos = go[pos][i];
            ans |= (1 << i);
        }
    }

    if(curr <= x) return ans+1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    w[0] = INF;
    w[1] = 0;

    ll last = 0;
    int cnt = 1;
   	
    for(int i = 0; i < LOGN; i++) {
        go[0][i] = go[1][i] = 0;
        sum[0][i] = sum[1][i] = INF;
    }

    int Q; cin >> Q;

    while(Q--) {
    	int op; cin >> op;

    	if(op == 1) {
    		ll p, q; cin >> p >> q;
    		int r = p^last;
    		int W = q^last;

    		cnt++;

    		w[cnt] = W;

    		if(w[r] >= w[cnt]) {
    			go[cnt][0] = r;
    		}
    		else {
    			int pos = r;

                for(int i = LOGN-1; i >= 0; i--) {
    				if(w[go[pos][i]] < w[cnt]) {
    					pos = go[pos][i];
    				}
    			}

    			pos = go[pos][0];
    			go[cnt][0] = pos;
    		}

            sum[cnt][0] = min(INF, (ll) w[cnt] + w[go[cnt][0]]);

    		for(int j = 1; j < LOGN; j++) {
    			go[cnt][j] = go[go[cnt][j-1]][j-1];
    			sum[cnt][j] = min(INF, sum[cnt][j-1] + sum[go[cnt][j-1]][j-1] - w[go[cnt][j-1]]);
    		}

            // if(cnt == 5) {
            //     for(int j = 0; j < 3; j++)
            //         cout << go[cnt][j] << " " << sum[cnt][j] << "\n";
            // }
    	}
    	else {
    		ll p, q; cin >> p >> q;
    		int r = p^last;
    		ll x = q^last;

    		last = solve(r, x);

            cout << last << "\n";
    	}
    }
	
	
    return 0;
}
