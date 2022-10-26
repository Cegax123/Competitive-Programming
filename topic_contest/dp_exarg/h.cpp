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

struct Task {
    int a, b, id;
};

bool cmp(const Task& a, const Task& b) {
    return a.a - a.b > b.a - b.b;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, c; cin >> n >> c;
    vector<Task> tasks;

    for(int i = 0; i < n; i++) {
        int d, s; cin >> d >> s;
        if(d < s) d = s;

        tasks.pb({d, s, i});
    }

    sort(all(tasks), cmp);

    int dp[n+1][n+1];
    ii p[n+1][n+1];

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i <= n; i++)
        dp[i][0] = c;

    for(int i = 1; i <= n; i++) {
        for(int k = 0; k < i; k++) {
            for(int j = 0; j <= k; j++) {
                if(dp[k][j] != -1 and dp[k][j] >= tasks[i-1].a) {
                    if(dp[i][j+1] < dp[k][j] - tasks[i-1].b) {
                        dp[i][j+1] = dp[k][j] - tasks[i-1].b;
                        p[i][j+1] = {k, j};
                    }
                }
            }
        }
    }

    int ans = -1, x, y;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(dp[i][j] != -1 and ans < j) {
                ans = j;
                x = i, y = j;
            }
        }
    }

    vi ord;

    while(y) {
        ord.pb(tasks[x-1].id);
        ii tmp = p[x][y];

        x = tmp.first;
        y = tmp.second;
    }

    reverse(all(ord));

    cout << ans << "\n";

    for(int  x : ord)
        cout << x+1 << " ";
	
    return 0;
}


