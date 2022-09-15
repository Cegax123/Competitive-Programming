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

    vi a(n+1), b(m+1), c(n+m+1);

    for(int i = 0; i <= n; i++)
        cin >> a[i];
	
    for(int i = 0; i <= n+m; i++)
        cin >> c[i];

    for(int i = m; i >= 0; i--) {
        b[i] = c[i+n]/a[n];
        
        for(int j = 0; j <= n; j++)
            c[i+j] -= b[i] * a[j];
    }

    for(int i = 0; i <= m; i++)
        cout << b[i] << " ";
	
	return 0;
}

