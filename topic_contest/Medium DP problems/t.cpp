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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vii a(n);
        
        for(int i = 0; i < n; i++) 
            cin >> a[i].first >> a[i].second;

        sort(all(a), [&](const ii& x, const ii& y) {
                return x.first < y.first or (x.first == y.first and x.second > y.second);
                });

        reverse(all(a));

        const int INF = 1e9;
        vi d(n+5, INF);

        for(int i = 0; i < n; i++) {
            int x = a[i].second;

            int l = 1, r = n+4;

            while(l < r) {
                int m = (l+r) >> 1;
                if(d[m] > x) r = m;
                else l = m + 1;
            }

            d[l] = x;
        }

        for(int i = n; i >= 1; i--) {
            if(d[i] != INF) {
                cout << i << "\n";
                break;
            }
        }
    }

	
    return 0;
}


