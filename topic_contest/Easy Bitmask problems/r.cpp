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
    int n, m; cin >> n >> m;
    vector<string> names(n);

    for(int i = 0; i < n; i++) cin >> names[i];

    sort(all(names));

    map<string, int> id;

    for(int i = 0; i < n; i++)
        id[names[i]] = i;

    vector<vector<bool> > hate(n, vector<bool>(n, 0));
    while(m--) {
        string a, b; cin >> a >> b;
        hate[id[a]][id[b]] = 1;
        hate[id[b]][id[a]] = 1;
    }

    int mask = 0;
    int ans = 0;
    for(int i = 0; i < (1 << n); i++) {
        vi curr;
        for(int j = 0; j < n; j++) {
            if((i >> j)&1) curr.pb(j);
        }

        bool cmp = 1;
        for(int x : curr)
            for(int y : curr)
                if(hate[x][y]) cmp = 0;

        if(cmp == 0) continue;

        if((int) curr.size() > ans) {
            ans = curr.size();
            mask = i;
        }
    }

    cout << ans << "\n";
    for(int i = 0; i < n; i++)
        if(mask&(1 << i)) cout << names[i] << "\n";

    return 0;
}


