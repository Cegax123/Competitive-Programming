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

const int maxn = 1e4+5;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi cnt(maxn, 0);

        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a]++;
        }
        
        int ans = 0;
        for(int i = 0; i < maxn; i++) {
            if(cnt[i] >= 2) {
                if(cnt[i] & 1) cnt[i] = 1;
                else cnt[i] = 2;
            }

            ans += (cnt[i] > 0);
        }
        
        int two = 0;
        for(int i = 0; i < maxn; i++) 
            two += cnt[i] == 2;

        if(two&1) ans--;
        
        cout << ans << "\n";
    }

	
    return 0;
}


