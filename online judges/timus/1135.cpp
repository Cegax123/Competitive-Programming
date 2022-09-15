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

    string tot = "";
    string s; 

    while(cin >> s) 
        tot += s;

    ll ans = 0;
    int target = n-1;

    for(int i = n-1; i >= 0; i--) {
        if(tot[i] == '<') continue;
        ans += (ll) target - i;
        target--;
    }
    
    cout << ans << "\n";

	return 0;
}

