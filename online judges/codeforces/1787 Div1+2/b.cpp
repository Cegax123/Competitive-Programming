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
        vii a;

        auto insert = [&](int x) {
            if(n%x == 0) {
                a.pb({0, x});
            }
            while(n%x == 0) {
                a.back().first++;
                n/=x;
            }
        };

        for(int i = 2; i * i <= n; i++) {
            insert(i);
        }
        if(n != 1) insert(n);

        sort(all(a));
        reverse(all(a));

        ll ans = 0;

        while(!a.empty()) {
            ll p = a.back().first;
            ll curr = p;
            
            for(int i = a.size()-1; i >= 0; i--) {
                curr *= a[i].second;

                a[i].first -= p;
                if(a[i].first == 0) a.pop_back();
            }
            ans += curr;
        }
        cout << ans << "\n";
    }

	
    return 0;
}


