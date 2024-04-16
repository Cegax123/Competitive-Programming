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

string e;
int p, m;

const int maxn = 1e4+5;
const int maxp = 105;
const int INF = 1e9;
int u[maxn];
int v[maxn];
vi adj[maxn];

int dp1[maxn][maxp], dp2[maxn][maxp];
int sign;

void dfs(int t) {
    if(adj[t].empty()) {
        dp1[t][0] = dp2[t][0] = v[t];
    }
    else if((int) adj[t].size() == 1) {
        int to = adj[t][0];
        dfs(to);

        for(int i = 0; i < maxp; i++) {
            dp1[t][i] = dp1[to][i];
            dp2[t][i] = dp2[to][i];
        }
    }
    else {
        int l = adj[t][0], r = adj[t][1];

        dfs(l); dfs(r);

        for(int i = 0; i < maxp; i++) {
            for(int j = 0; j < maxp; j++) {
                if(i+j >= maxp) continue;

                if(dp1[l][i] != -INF and dp1[r][j] != -INF) {
                    dp1[t][i+j] = max(dp1[t][i+j], dp1[l][i] - sign * dp1[r][j]);
                    dp2[t][i+j] = min(dp2[t][i+j], dp1[l][i] - sign * dp1[r][j]);
                }

                if(dp1[l][i] != -INF and dp2[r][j] != INF) {
                    dp1[t][i+j] = max(dp1[t][i+j], dp1[l][i] - sign * dp2[r][j]);
                    dp2[t][i+j] = min(dp2[t][i+j], dp1[l][i] - sign * dp2[r][j]);
                }

                if(dp2[l][i] != INF and dp1[r][j] != -INF) {
                    dp1[t][i+j] = max(dp1[t][i+j], dp2[l][i] - sign * dp1[r][j]);
                    dp2[t][i+j] = min(dp2[t][i+j], dp2[l][i] - sign * dp1[r][j]);
                }

                if(dp2[l][i] != INF and dp2[r][j] != INF) {
                    dp1[t][i+j] = max(dp1[t][i+j], dp2[l][i] - sign * dp2[r][j]);
                    dp2[t][i+j] = min(dp2[t][i+j], dp2[l][i] - sign * dp2[r][j]);
                }
            }
        }

        for(int i = 0; i < maxp; i++) {
            for(int j = 0; j < maxp; j++) {
                if(i+j+1 >= maxp) continue;

                if(dp1[l][i] != -INF and dp1[r][j] != -INF) {
                    dp1[t][i+j+1] = max(dp1[t][i+j+1], dp1[l][i] + sign * dp1[r][j]);
                    dp2[t][i+j+1] = min(dp2[t][i+j+1], dp1[l][i] + sign * dp1[r][j]);
                }

                if(dp1[l][i] != -INF and dp2[r][j] != INF) {
                    dp1[t][i+j+1] = max(dp1[t][i+j+1], dp1[l][i] + sign * dp2[r][j]);
                    dp2[t][i+j+1] = min(dp2[t][i+j+1], dp1[l][i] + sign * dp2[r][j]);
                }

                if(dp2[l][i] != INF and dp1[r][j] != -INF) {
                    dp1[t][i+j+1] = max(dp1[t][i+j+1], dp2[l][i] + sign * dp1[r][j]);
                    dp2[t][i+j+1] = min(dp2[t][i+j+1], dp2[l][i] + sign * dp1[r][j]);
                }

                if(dp2[l][i] != INF and dp2[r][j] != INF) {
                    dp1[t][i+j+1] = max(dp1[t][i+j+1], dp2[l][i] + sign * dp2[r][j]);
                    dp2[t][i+j+1] = min(dp2[t][i+j+1], dp2[l][i] + sign * dp2[r][j]);
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxp; j++) {
            dp1[i][j] = -INF;
            dp2[i][j] = INF;
        }
    }

    cin >> e >> p >> m;

    if(p <= m) sign = 1;
    else sign = -1;

    e = "(" + e + ")";

    stack<int> st;
    int id = 0;

    for(int i = 0; i < (int) e.size(); i++) {
        if(e[i] == '(') {
            st.push(id++);
        }
        else if(e[i] == ')') {
            int x = st.top();
            st.pop();
            if(!st.empty()) {
                u[x] = st.top();
            }
        }
        else if(e[i] >= '0' and e[i] <= '9') {
            v[id] = e[i]-'0';
            u[id] = st.top();

            id++;
        }
    }

    for(int i = 1; i < id; i++) { 
        adj[u[i]].pb(i);
    }

    dfs(0);

    cout << dp1[0][min(p, m)] << "\n";

    return 0;
}


