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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    multiset<int> unused, sold;

    unused.insert(INF);
    sold.insert(INF);


    ll ans = 0;

    for(int i = 0; i < n; i++) {
        int p; cin >> p;

        int u = *unused.begin();
        int s = *sold.begin();
        
        if(min(u, s) < p) {
            if(u < s) {
                ans -= u;
                ans += p;

                unused.erase(unused.begin());
            }
            else {
                unused.insert(s);
                sold.erase(sold.begin());

                ans -= s;
                ans += p;
            }

            sold.insert(p);
        }
        else unused.insert(p);
    }

    cout << ans << "\n";

    return 0;
}

