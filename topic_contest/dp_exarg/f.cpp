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

const int maxt = 2005;

struct Item {
    int t, d, p, id;
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;

    vector<Item> items;

    for(int i = 0; i < n; i++) {
        int t, d, p; cin >> t >> d >> p;
        if(t >= d) continue;

        items.pb({t, d, p, i+1});
    }

    n = items.size();

    if(n == 0) { 
        cout << "0\n0\n";
        return 0;
    }

    sort(all(items), [&] (const Item& a, const Item& b) {
            return a.d < b.d;
            });

    ii p[n][maxt];

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < maxt; j++)
            p[i][j] = {-1, -1};

    int dp[n][maxt];
    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++)
        dp[i][items[i].t] = items[i].p;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            for(int T = 0; T < maxt; T++) { 
                if(dp[j][T] == -1) continue;

                if(T + items[i].t < items[i].d) {
                    if(dp[i][T + items[i].t] < dp[j][T] + items[i].p) {
                        dp[i][T + items[i].t] = dp[j][T] + items[i].p;
                        p[i][T + items[i].t] = {j, T};
                    }
                }
            }
        }
    }

    

    int ans = 0;
    int x, y;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < maxt; j++) {
            if(dp[i][j] > ans) {
                ans = dp[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout << ans << "\n";

    vi lst;

    while(make_pair(x, y) != make_pair(-1, -1)) { 
        lst.pb(items[x].id);

        ii tmp = p[x][y];
        
        x = tmp.first;
        y = tmp.second;
    }

    cout << lst.size() << "\n";

    reverse(all(lst));

    for(int u : lst)
        cout << u << " ";
	
    return 0;
}


