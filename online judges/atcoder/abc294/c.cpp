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
    int a[n], b[m];

    vi c;

    for(int i = 0; i < n; i++) cin >> a[i], c.pb(a[i]);
    for(int i = 0; i < m; i++) cin >> b[i], c.pb(b[i]);

    sort(all(c));

    map<int, int> order;

    for(int i = 0; i < n+m; i++)
        order[c[i]] = i + 1;

    for(int i = 0; i < n; i++) cout << order[a[i]] << " ";
    cout << "\n";
    for(int i = 0; i < m; i++) cout << order[b[i]] << " ";
	
    return 0;
}


