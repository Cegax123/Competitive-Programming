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

const int maxn = 2e5;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n; cin >> n;
    int a[n];
    set<int> s;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    map<int, int> id;
    int ind = 1;
    for(int x : s)
        id[x] = ind++;

    for(int i = 0; i < n; i++)
        a[i] = id[a[i]];
	
    vi c(maxn+5, INF);
    int ans = 1;

    c[1] = a[0];

    for(int i = 1; i < n; i++) {
        int l = 1, r = maxn;

        while(l < r) {
            int m = (l+r+1) >> 1;
            if(c[m] < a[i]) l = m;
            else r = m-1;
        }

        if(c[l] < a[i]) {
            c[l+1] = min(c[l+1], a[i]);
            ans = max(ans, l+1);
        }
        else 
            c[1] = min(c[1], a[i]);
    }

    cout << ans << "\n";
	
	return 0;
}

