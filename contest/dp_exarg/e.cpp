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

const int maxn = 205;
vi a, b, c;
ll dp[maxn][maxn][maxn];

ll calc(int R, int G, int B) {
    if(R + G + B <= 1)
        return 0;

    if(dp[R][G][B] != -1)
        return dp[R][G][B];

    ll ans = 0;
    int x = a[R-1], y = b[G-1], z = c[B-1];
    
    if(R and G) ans = max(ans, calc(R-1, G-1, B) + x * y);
    if(G and B) ans = max(ans, calc(R, G-1, B-1) + z * y);
    if(R and B) ans = max(ans, calc(R-1, G, B-1) + x * z);

    return dp[R][G][B] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp, -1, sizeof(dp));

	int R, G, B; cin >> R >> G >> B;

    a.resize(R);
    b.resize(G);
    c.resize(B);

    for(int i = 0; i < R; i++)
        cin >> a[i];

    for(int i = 0; i < G; i++)
        cin >> b[i];

    for(int i = 0; i < B; i++)
        cin >> c[i];

    sort(all(a));
    sort(all(b));
    sort(all(c));

    cout << calc(R, G, B) << "\n";

    return 0;
}


