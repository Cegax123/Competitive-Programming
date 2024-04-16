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
        vi cnt(n+1, 0);
        vi d[n+1];
        vii a;

        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            a.pb({x, y});
            d[x].pb(y);
        }

        for(int i = 1; i <= n; i++) {
            sort(all(d[i]));
            reverse(all(d[i]));
        }


        int x = 0;
        ll sum = 0;

        deque<ii> dq;

        auto cmp = [&]() {
            if(!dq.empty() and dq.front().first == x) {
                x -= dq.front().second;
                dq.pop_front();
            }
        };

        for(int i = 1; i <= n; i++) {
            int cnt = 0;
            for(int y : d[i]) {
                if(x < i) {
                    sum += y;
                    cnt++;
                    x++;
                    
                    cmp();
                }
            }

            dq.pb({i, cnt});
            cmp();
        }

        cout << sum << "\n";
    }

	
    return 0;
}


