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
    ll n, m; cin >> n >> m;
    set<int> s[m+1];

    for(int i = 1; i <= n; i++) {
        ll x;  cin >> x;
        
        ll l = 1, r = m;

        while(l < r) {
            ll mi = (l+r) >> 1;
            if(x + mi * i >= 0) r = mi;
            else l = mi+1;
        }

        ll L = (x + l * i >= 0 ? l : -1);

        l = 1, r = m ;
        while(l < r) {
            ll mi = (l+r+1) >> 1;
            if(x + mi * i <= n) l = mi;
            else r = mi-1;
        }

        ll R = (x + i * l <= n ? l : -1);

        if(L != -1 and R != -1 and L <= R) {
            for(int j = L; j <= R; j++) {
                s[j].insert(x + j * i);
            }
        }
    }

    for(int i = 1; i <= m; i++) {
        int mex = 0;
        while(s[i].count(mex)) mex++;

        cout << mex << "\n";
    }
	
    return 0;
}


