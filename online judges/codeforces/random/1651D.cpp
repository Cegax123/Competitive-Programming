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

const int maxn = 2e5+5;
const int INF = 1e9;

int n;
int x[maxn], y[maxn];
map<ii, int> id;
bool used[maxn];

ii ans[maxn];
int len[maxn];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        id[{x[i], y[i]}] = i;
    }
	
    queue<int> q;
    
    vector<bool> used(n+1, 0);
    ii ans[n+1];

    for(int i = 1; i <= n; i++) {
        for(int d = 0; d < 4; d++) {
            int nx = x[i]+dx[d], ny = y[i]+dy[d];

            if(id[{nx, ny}] == 0) {
                q.push(i);
                used[i] = 1;

                ans[i] = {nx, ny};
            }
        }
    }

    while(!q. empty()) {
        int i = q.front(); q.pop();

        for(int d = 0; d < 4; d++) {
            int nx = x[i]+dx[d], ny = y[i]+dy[d];

            int nxt = id[{nx, ny}];

            if(nxt and !used[nxt]) {
                used[nxt] = 1;
                ans[nxt] = ans[i];

                q.push(nxt);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
	
	return 0;
}


