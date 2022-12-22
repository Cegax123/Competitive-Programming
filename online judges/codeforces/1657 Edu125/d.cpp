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
    int n, C; cin >> n >> C;
    map<int, ll> mp;

    for(int i = 0; i < n; i++) {
        int c; ll d, h; cin >> c >> d >> h;
        mp[c] = max(mp[c], d * h);
    }

    ll maxF[C+1];
    memset(maxF, 0, sizeof(maxF));

    for(auto e : mp) {
        int c = e.first; ll f = e.second;

        for(int i = c; i <= C; i += c) {
            maxF[i] = max(maxF[i], f * (i / c));
        }
    }

    for(int i = 1; i <= C; i++)
        maxF[i] = max(maxF[i], maxF[i-1]);
    
    int m; cin >> m;

    while(m--) {
        ll d, h; cin >> d >> h;
        ll f = d * h;

        int l = 0, r = C;
        while(l < r) {
            int m = (l+r) >> 1;
            if(maxF[m] > f) r = m;
            else l = m + 1;
        }

        if(maxF[l] > f) cout << l << " ";
        else cout << -1 << " ";
    }
	
    return 0;
}


