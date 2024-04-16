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
int a[maxn];
int cnt[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        auto get_mex = [&](int n) {
            for(int i = 0; i < n; i++) {
                if(a[i] < maxn) cnt[a[i]]++;
            }

            int ans = 0;

            for(int i = 0; i < maxn; i++) {
                if(!cnt[i]) {
                    ans = i;
                    break;
                }
            }


            for(int i = 0; i < n; i++) {
                if(a[i] < maxn) cnt[a[i]]--;
            }
            return ans;
        };

        int m = get_mex(n);

        vi pos;

        for(int i = 0; i < n; i++) {
            if(a[i] == m+1)
                pos.pb(i);
        }

        if(pos.empty()) {
            bool ans = 0;

            for(int i = 0; i < n; i++) {
                if(a[i] > m) ans = 1;
            }

            for(int i = 0;  i < n; i++) {
                if(a[i] < maxn) cnt[a[i]]++;
            }

            for(int i = 0; i <= m; i++) {
                if(cnt[i] > 1) ans = 1;
            }
            for(int i = 0;  i < n; i++) {
                if(a[i] < maxn) cnt[a[i]]--;
            }

            cout << (ans ? "Yes\n" : "No\n");
            continue;
        }

        for(int i = pos[0]; i <= pos.back(); i++)
            a[i] = m;

        int new_m = get_mex(n);

        if(new_m == m+1) cout << "Yes\n";
        else cout << "No\n";
    }

	
    return 0;
}


