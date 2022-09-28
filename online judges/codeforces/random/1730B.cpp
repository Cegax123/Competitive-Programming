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

double x[maxn];
double t[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int i = 0; i < n; i++) cin >> t[i];

        auto f = [&](double y) {
            double mx = 0;
            for(int i = 0; i < n; i++) {
                mx = max(mx, abs(y-x[i]) + t[i]);
            }
            return mx;
        };

        double l = 0, r = 1e9;

        for(int i = 0; i < 1; i++) {
            double m1 = (l+r) / 3.0, m2 = (l+r) * 2.0 / 3.0;

            if(f(m1) < f(m2)) r = m2;
            else l = m1;
        }

        cout << fixed << setprecision(12) << l << "\n";
    }

	
    return 0;
}


