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
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;

        vi a(n);
        for(int i = 0; i < n; i++) 
            cin >> a[i];

        vi b(n);
        iota(all(b), 0);

        sort(all(b), [&](int x, int y) {
                return a[x] < a[y];
            });

        int min_el = a[b[0]];

        if(min_el == INF) {
            cout << INF << "\n";
            continue;
        }

        vector<vi> mark;
        int ind = 0;
        while(ind < n) {
            vi curr;
            int x = a[b[ind]];

            while(ind < n and x == a[b[ind]]) {
                curr.pb(b[ind]);
                ind++;
            }

            mark.pb(curr);
        }

        int lmt = 0;
        int sum = 0;
        for(int i = 0; i < (int) mark.size(); i++) {
            sum += mark[i].size();
            if(sum <= k) lmt = i+1;
        }

        auto get_ans = [&](int lmt) {
            vi tmp = a;
            int tmpk = k;

            for(int i = 0; i < lmt; i++) {
                for(int x : mark[i]) {
                    tmp[x] = INF;
                    tmpk--;
                }
            }

            int minel = *min_element(all(tmp));

            int ans = 0;

            for(int i = 0; i < n; i++) {
                if(tmpk) ans = max(ans, min(2 * minel, tmp[i]));

                if(i) ans = max(ans, min(2 * minel, min(tmp[i], tmp[i-1])));
                if(i+1 < n) ans = max(ans, min(2 * minel, min(tmp[i], tmp[i+1])));
            }

            return ans;
        };

        int ans = get_ans(lmt);
        if(lmt) ans = max(ans, get_ans(lmt-1));

        cout << ans << "\n";
    }

    return 0;
}


