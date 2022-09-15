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
	vi a(3);

    cin >> a[0] >> a[1] >> a[2];

    sort(all(a));

    int ans = a[2]-a[1] + ((a[1]-a[0])&1) + ((a[1]-a[0]+1) >> 1);

    cout << ans << "\n";
	
	
	return 0;
}

