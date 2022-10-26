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
    int n; cin >> n;
    int a[n+1][n+1];

    ii pos[n * n + 1];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            pos[a[i][j]] = {i, j};
        }
    }

    int sumr[n+1], sumc[n+1];

    memset(sumr, 0, sizeof(sumr));
    memset(sumc, 0, sizeof(sumc));

    ll ans = 0;

    for(int i = 1; i <= n * n; i++) {
        int x = pos[i].first, y = pos[i].second;
        ll a = sumr[x];
        ll ca = n-1-a;

        ll b = sumc[y];
        ll cb = n-1-b;

        ans += a * cb + b * ca;
        sumr[x]++;
        sumc[y]++;
    }

    cout << ans / 2 << "\n";
	
    return 0;
}


