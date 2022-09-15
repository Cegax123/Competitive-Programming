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

struct Monster {
    int a, h;
};

int f(int x) {
    return x * (x+1) / 2;
}

bool cmp(const Monster& a, const Monster& b) {
    return a.a * b.h > a.h * b.a;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        int n; cin >> n;

        vector<Monster> monsters;
        ll T = 0;

        for(int i = 0; i < n; i++) {
            int h, a; cin >> h >> a;

            T += a;

            int l = 0, r = 1000;

            while(l < r) {
                int m = (l+r) / 2;
                
                if(f(m) >= h) r = m;
                else l = m+1;
            }
            
            monsters.pb({a, l});
        }

        sort(all(monsters), cmp);

        // for(int i = 0; i < n; i++)
        //     cout << monsters[i].a << " " << monsters[i].h << endl;

        ll ans = 0;

        for(int i = 0; i < n; i++) {
            ans += (ll) T * monsters[i].h;

            T -= monsters[i].a;
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }

	
    return 0;
}


