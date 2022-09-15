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

const int maxn = 1e5;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi pos[maxn+5];

        for(int i = 0; i < n; i++) {
            int a; cin >> a;
            pos[a].pb(i+1);
        }

        int L = 1;
        bool comp = true;
        for(int i = 1; i <= maxn; i++) {
            if(pos[i].empty()) continue;

            int cnt[2] = {0, 0};
            
            for(int p : pos[i]) 
                cnt[p&1]++;

            int k = pos[i].size();
            int odd = (k+1) >> 1, even = k >> 1;

            if(L%2 == 0) swap(odd, even);

            if(cnt[0] != even or cnt[1] != odd) comp = false;

            L += k;
        }

        if(comp) cout << "YES\n";
        else cout << "NO\n";
    }
	
	
	return 0;
}

