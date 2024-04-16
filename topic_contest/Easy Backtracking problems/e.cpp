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

const int maxn = 10;

int n, a[3];
int l[maxn];
int ans = -1;
int curr[4];
int comb[4];

void solve(int pos = 0) {
    if(pos == n) {
        int local = 0;
        for(int i = 0; i < 3; i++) {
            local += abs(a[i]-curr[i]);
            if(comb[i] == 0) return;
            local += 10 * (comb[i]-1);
        }
        if(ans == -1) ans = local;
        ans = min(ans, local);
        return;
    }
    for(int i = 0; i < 4; i++) {
        curr[i] += l[pos];
        comb[i]++;
        solve(pos+1);
        curr[i] -= l[pos];
        comb[i]--;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> a[0] >> a[1] >> a[2];
    for(int i = 0; i < n; i++)
        cin >> l[i];

    solve();
    cout << ans << "\n";
	
    return 0;
}


