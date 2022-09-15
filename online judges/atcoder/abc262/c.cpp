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
    int a[n+1];
    ll cnt = 0;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == i) cnt++;
    }

    ll ans = (ll) cnt * (cnt-1) / 2;

    for(int i = 1; i <= n; i++) {
        if(a[i] != i and i < a[i]) {
            if(a[a[i]] == i)
                ans++;
        }
    }

    cout << ans << "\n";
	
    return 0;
}


