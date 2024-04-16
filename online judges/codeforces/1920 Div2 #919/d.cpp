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

const int maxn = 1e5 + 5;
const ll INF = 2e18;
pair<int, int> op[maxn];


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;

        vector<int> el;

        for(int i = 0; i < n; i++) {
            int t, x; cin >> t >> x;
            op[i] = {t, x};

            if(t == 1) el.push_back(x);
        }

        int ind = 0;
        ll len = 0;
        
        vector<ll> l;
        vector<int> b;

        vector<int> py;

        int sumy = 0;

        while(ind < n) {
            if(op[ind].first == 1) {
                int y = 0;
                while(ind < n and op[ind].first == 1) {
                    y++;
                    ind++;
                }

                len = min(INF, len + y);
                l.push_back(len);

                b.push_back(y);
                sumy += y;
                py.push_back(sumy);
            }
            else {
                ll x = 1;

                while(ind < n and op[ind].first == 2) {
                    if(x < INF / (op[ind].second+1)) x *= op[ind].second+1;
                    else x = INF;

                    ind++;
                }

                if(len < INF / x) {
                    len *= x;
                }
                else len = INF;

                l.push_back(len);
                b.push_back(x);
            }
        }

        //for(int i = 0; i < (int) l.size(); i++) cout << l[i] << "\n";

        while(q--) {
            ll pos; cin >> pos;
            int ind = 0;

            for(int i = 0; i < (int) l.size(); i++) {
                if(pos <= l[i]) {
                    ind = i;
                    break;
                }
            }

            int ans = -1;
            while(true) {
                if(ind % 2 == 0) {
                    ll curr = l[ind], last = curr - b[ind] + 1;

                    if(last <= pos and pos <= curr) {
                        int elpos = pos-last+(ind == 0 ? 0 : py[ind/2-1]);
                        ans = el[elpos];
                        break;
                    }
                    else {
                        ind--;
                    }
                }
                else {
                    pos--;
                    pos %= l[ind-1];
                    pos++;
                    ind--;
                }
            }

            cout << ans << " ";
        }
        cout << "\n";
    }

	
    return 0;
}


