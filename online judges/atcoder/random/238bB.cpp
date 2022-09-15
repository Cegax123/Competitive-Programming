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
	int n; cin >> n;
    vi c(1, 0);

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        
        for(int& el : c)
            el = (el+a)%360;

        c.pb(0);
        sort(all(c));
    }

    int ans = 0;
	for(int i = 0; i < n; i++) 
        ans = max(ans, abs(c[i+1]-c[i]));

    ans = max(ans, abs(c[n]-360));

    cout << ans << "\n";
	
	return 0;
}

