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
    int n, w, h; cin >> n >> w >> h;
    vector<pair<ii, int>> a;

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if(x > w and y > h) a.pb({{x, y}, i+1});
    }

    sort(all(a));

    if(a.empty()) {
        cout << 0 << "\n";
        return 0;
    }

    n = a.size();

    int dp[n], p[n];

    for(int i = 0; i < n; i++) {
        p[i] = i;
        dp[i] = 1;

        for(int j = 0; j < i; j++) {
            if(a[j].first.first < a[i].first.first and a[j].first.second < a[i].first.second) {
                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    p[i] = j;
                }
            }
        }
    }

    int idx = -1, mx = -1;

    for(int i = 0; i < n; i++) {
        if(dp[i] > mx) {
            mx = dp[i];
            idx = i;
        }
    }

    vi ord;

    while(p[idx] != idx) {
        ord.pb(a[idx].second);
        idx = p[idx];
    }

    ord.pb(a[idx].second);

    reverse(all(ord));

    cout << ord.size() << "\n";
    for(int x : ord) cout << x << " ";
	
    return 0;
}


