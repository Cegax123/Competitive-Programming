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
    const int INF = 1e9;
    while(t--) {
        int n, k; cin >> n >> k;
        vi a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        auto cmp = [&](int x) {
            vi b = a;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(b[i] * 2 < x) {
                    cnt++;
                    b[i] = INF;
                }
            }

            int mn = 2;

            for(int i = 1; i < n; i++) {
                int poss = 0;
                if(b[i-1] < x) poss++;
                if(b[i] < x) poss++;
                mn = min(mn, poss);
            }

            return cnt + mn <= k;
        };

        int l = 1, r = 1e9;
        while(l < r) {
            int m = (l+r+1) >> 1;
            if(cmp(m)) l = m;
            else r = m-1;
        }

        cout << l << "\n";
    }


    return 0;
}


