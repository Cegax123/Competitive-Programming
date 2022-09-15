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

const int maxa = 150005;
vi pos[maxa];
int n;

int get_val(int i, int j, int x) {
    return pos[x][i] + 1 + n-1-pos[x][j];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
    while(t--) {
        cin >> n;
    
        int a[n];
        set<int> s;
        map<int, int> id;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }

        int ind = 0;

        for(int x : s) {
            id[x] = ind++;
        }

        for(int i = 0; i < n; i++) {
            a[i] = id[a[i]];
            pos[a[i]].pb(i);
        }

        int ans = -1;
        for(int i = 0; i < n; i++) {
            if((int) pos[i].size() <= 1) continue;
            int k = pos[i].size();

            for(int j = 0; j+1 < k; j++) {
                ans = max(ans, get_val(j, j+1, i));
            }
        }

        cout << ans << "\n";

        for(int i = 0; i < n; i++)
            pos[i].clear();
    }
	
	
	return 0;
}

