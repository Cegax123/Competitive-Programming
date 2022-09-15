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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    vector<ll> cnt(maxn, 0);

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
    }

    ll ans = 0;

    for(int i = 1; i < maxn; i++) {
        if(cnt[i] == 0) continue;

        for(int j = 1; j * j <= i; j++) {
            if(i % j) continue;

            int d1 = j, d2 = i/j;

            if(d1 != d2) ans += cnt[i] * cnt[d1] * cnt[d2] * 2;
            else ans += cnt[i] * cnt[d1] * cnt[d1];
        }
    }

    cout << ans << "\n";
   
    return 0;
}


