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

const int maxn = 1e5+5;
const int INF = 1e9;

vi adj[maxn];
int dp[maxn][3];

int mx(int v) {
    int ans = -INF;
    int ind = -1;
    for(int i = 0; i < 3; i++) {
        if(dp[v][i] == -1) continue;
        int curr = dp[v][i] + (i == 1);
        if(curr >= ans) {
            ans = curr;
            ind = i;
        }
    }

    return ind;
}

void dfs(int v, int p) {
    int sum = 0;
    vii max_dp0(3, {-1, -1}), max_dp2(3, {-1, -1});
    
    for(int to : adj[v]) {
        dfs(to, v);
    
        int add = dp[to][mx(to)] + (mx(to) == 1);

        sum += add;
        
        if(dp[to][0] != -1) {
            max_dp0[0] = {dp[to][0]-add, to};
            sort(all(max_dp0));
        }

        if(dp[to][2] != -1) {
            max_dp2[0] = {dp[to][2]-add, to};
            sort(all(max_dp2));
        }
    }

    dp[v][0] = dp[v][1] = dp[v][2] = sum;

    if(max_dp0[1].second != -1 and max_dp0[2].second != -1) 
        dp[v][2] += max_dp0[1].first + max_dp0[2].first;
    else 
        dp[v][2] = -1;

    int global = -INF;
    for(int i = 0; i < 3; i++) {
        int local = 0;
        int u = -1, s = -1;

        for(int k = 0; k < 3; k++) {
            if(i == k) continue;

            if(u == -1) u = max_dp0[k].second;
            else s = max_dp0[k].second;
            
            local += max_dp0[k].first;
        }

        if(u == -1 or s == -1) continue;

        for(int j = 0; j < 3; j++) {
            int x = max_dp2[j].second;
            if(x == -1) continue;

            if(x == u or x == s) continue;
            global = max(global, local + max_dp2[j].first);
        }
    }

    if(global == -INF) dp[v][1] = -1;
    else dp[v][1] += global;

    //cout << v << ": " << dp[v][0] << " " << dp[v][1] << " " << dp[v][2] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	
    for(int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        adj[p].pb(i);
    }

    dfs(0, 0);

    cout << max({dp[0][0], dp[0][1], dp[0][2]});
	
	return 0;
}

