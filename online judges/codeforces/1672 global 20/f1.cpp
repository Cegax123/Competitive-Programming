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
	int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        vi cnt(n+1, 0);
        vi pos[n+1];

        deque<ii> a;

        for(int i = 0; i < n; i++) {
            int x; cin >> x;

            pos[x].pb(i);
            cnt[x]++;
        }

        for(int i = 1; i <= n; i++) 
            if(cnt[i]) a.pb({cnt[i], i});

        vi bucket[n+1];
        sort(all(a));

        while(!a.empty()) {
            int x = a[0].first;
            int k = a.size();

            for(int i = 0; i < k; i++) {
                int nxt = a[(i+1)%k].second;
                for(int j = 0; j < x; j++) {
                    bucket[a[i].second].pb(nxt);
                }
                a[i].first -= x;
            }

            while(!a.empty() and a[0].first == 0)
                a.pop_front();
        }

        int ans[n];
        for(int i = 1; i <= n; i++) {
            int k = pos[i].size();
            for(int j = 0; j < k; j++) {
                ans[pos[i][j]] = bucket[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }

        cout << "\n";
    }

	
    return 0;
}


