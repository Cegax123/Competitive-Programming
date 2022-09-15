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

struct Comp {
    int l, r, mini, maxi;
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        int p[n+1];
        int pos[n+1];

        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        vector<Comp> a;
        vector<bool> used(n+1, 0);

        for(int i = 1; i <= n; i++) {
            if(used[i]) continue;

            int R = pos[i], L = (a.empty() ? 1 : a.back().r+1);

            int min_i = i;
            int max_i = i;

            for(int j = L; j <= R; j++) {
                max_i = max(max_i, p[j]);
                used[p[j]] = 1;
            }

            int l = 0, r = a.size()-1;

            while(l < r) {
                int m = (l+r)/2;
                if(min_i < a[m].maxi) r = m;
                else l = m+1;
            }

            if(!a.empty() and min_i < a[l].maxi) {
                while(a.back().maxi != a[l].maxi) 
                    a.pop_back();

                Comp x = a.back(); a.pop_back();

                x.r = R;
                x.maxi = max(x.maxi, max_i);
                a.pb(x);
            }
            else {
                Comp x;
                x.l = L, x.r = R, x.mini = min_i, x.maxi = max_i;
                a.pb(x);
            }
        }

        cout << a.size() << "\n";
    }
	
	
	return 0;
}

