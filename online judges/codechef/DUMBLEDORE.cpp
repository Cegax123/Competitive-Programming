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
    
    ll a[n];
    memset(a, 0, sizeof(a));
    ll sum = 0;

    for(int i = 0; i < m; i++) {
        int p, c; cin >> p >> c;
        a[p-1] += c;
        sum += a[p-1];
        cout << sum << "\n";
    }

	
    return 0;
}


