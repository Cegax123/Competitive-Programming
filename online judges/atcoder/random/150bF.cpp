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

vector<int> z_function(const vector<int>& s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    const int L = 30;

    int n; cin >> n;
    int a[n], b[n];
    
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    int ans[n];
    memset(ans, 0, sizeof(ans));

    int cnt[n];
    memset(cnt, 0, sizeof(cnt));

    auto calc = [&](int x, int d) {
        vi s;

        for(int i = 0; i < n; i++) {
            int c = (b[i] >> d)&1;
            s.pb(c ^ x);
        }

        s.pb(2);

        for(int i = 0; i < n; i++)
            s.pb((a[i] >> d)&1);

        for(int i = 0; i < n; i++)
            s.pb((a[i] >> d)&1);

        vi z = z_function(s);

        for(int j = n+1; j <= 2 * n; j++) {
            if(z[j] == n) {
                cnt[j-n-1]++;
                ans[j-n-1] ^= (x << d);
            }
        }
    };

    for(int i = 0; i < L; i++) {
        calc(0, i);
        calc(1, i);
    }

    for(int i = 0; i < n; i++) {
        if(cnt[i] == L) cout << i << " " << ans[i] << "\n";
    }
	
    return 0;
}


