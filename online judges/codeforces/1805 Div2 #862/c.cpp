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

const int INF = 1e9;

struct Para {
    ll l, r;
    int ans = -INF;
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        ll n, m; cin >> n >> m;
        vector<ll> k(n);
        for(int i = 0; i < n; i++)
            cin >> k[i];
        sort(all(k));

        vector<Para> paras(m);

        for(int i = 0; i < m; i++) {
            ll a, b, c; cin >> a >> b >> c;

            if(c <= 0) {
                cout << "NO\n";
                continue;
            }

            ll l = 0, r = 1e9;

            while(l < r) {
                ll m = (l+r+1) >> 1;

                if(m * 1ll * m < 4ll * a * c) l = m;
                else r = m-1;
            }

            paras[i].l = -l + b, paras[i].r = l + b;

            //cout << -l+b << " " << l+b << endl;

            l = 0, r = n-1;

            while(l < r) {
                int m = (l+r+1) >> 1;

                if(k[m] <= paras[i].r) l = m;
                else r = m-1;
            }


            int L=0;
            if(k[l] <= paras[i].r) L = l;
            else L = -1;

            l = 0, r = n-1;

            while(l < r) {
                int m = (l+r) >> 1;

                if(k[m] >= paras[i].l) r = m;
                else l = m+1;
            }

            int R=0;
            if(k[l] >= paras[i].l) R = l;
            else R = n;

            if(L >= R) {
                cout << "YES\n";
                cout << k[L] << "\n";
            }
            else cout << "NO\n";
        }
        cout << "\n";


    }

	
    return 0;
}


