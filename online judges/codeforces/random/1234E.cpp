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
    int x[m];

    for(int i = 0; i < m; i++) 
        cin >> x[i];
	
    vi in[n+1], out[n+1];

    for(int i = 0; i < m-1; i++) 
        out[x[i]].pb(x[i+1]);

    for(int i = 1; i < m; i++)
        in[x[i]].pb(x[i-1]);

    int a[n+1];
    int pos[n+1];

    for(int i = 1; i <= n; i++) {
        pos[i] = i;
        a[i] = i;
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int v : out[i])
            ans += abs(pos[v]-pos[i]);
        for(int v : in[i])
            ans += abs(pos[v]-pos[i]);
    }

    cout << ans/2 << " ";

    for(int i = 2; i <= n; i++) {
        for(int v : out[a[1]]) 
            ans -= 2 * abs(pos[v]-1);
        for(int v : in[a[1]])
            ans -= 2 * abs(pos[v]-1);

        for(int v : out[a[i]]) 
            ans -= 2 * abs(pos[v]-i);
        for(int v : in[a[i]])
            ans -= 2 * abs(pos[v]-i);

        a[1]++;
        a[i]--;

        pos[a[1]] = 1;
        pos[a[i]] = i;


        for(int v : out[a[1]])
            ans += 2 * abs(pos[v]-1);
        for(int v : in[a[1]])
            ans += 2 * abs(pos[v]-1);

        for(int v : out[a[i]])
            ans += 2 * abs(pos[v]-i);
        for(int v : in[a[i]])
            ans += 2 * abs(pos[v]-i);

        cout << ans/2 << " ";
    }
	
	return 0;
}

