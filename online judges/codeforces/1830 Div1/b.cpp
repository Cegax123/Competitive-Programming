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

const int maxn = 2e5 + 5;
const int SQRTN = 650;

int cnt[SQRTN][maxn];
int a[maxn], b[maxn];
vii c;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        for(int i = 0; i < n; i++) {
            if(a[i] * 1ll * a[i] <= 2 * n) cnt[a[i]][b[i]]++;
            else c.pb({a[i], b[i]});
        }

        ll ans = 0;

        for(int i = 1; i * i <= 2 * n; i++) {
            ll curr = 0;
            
            if(i % 2 == 0) curr -= cnt[i][i * i / 2];

            for(int j = 1; j <= n; j++) {
                int target = i * i - j;

                if(target >= 1 and target <= n) curr += cnt[i][j] * 1ll * cnt[i][target];
            }

            ans += curr / 2;
        }

        for(int j = 0; j < n; j++) {
            int aj = a[j], bj = b[j];

            for(int i = 1; i * i <= 2 * n and aj > i; i++) {
                ll target = (ll) aj * i - bj;

                if(target >= 1 and target <= n) {
                    ans += cnt[i][target];
                }
            }
        }

        cout << ans << "\n";

        for(int i = 1; i * i <= 2 * n; i++)
            for(int j = 1; j <= n; j++)
                cnt[i][j] = 0;
    }

	
    return 0;
}


